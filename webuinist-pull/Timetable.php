<?php  namespace Calendar;

use Jsvrcek\ICS\Model\Description\Location;
use Jsvrcek\ICS\Model\Calendar;
use Jsvrcek\ICS\Model\CalendarEvent;
use Jsvrcek\ICS\Utility\Formatter;
use Jsvrcek\ICS\CalendarStream;
use Jsvrcek\ICS\CalendarExport;
use Jyggen\Curl\Request;
use Cache;
use DateInterval;
use DateTime;
use DateTimeZone;
use Exception;

class Timetable
{
    /**
     * Number of minutes timetables are cached for.
     */
    const TIMETABLE_CACHE_TIME = 120;
    /**
     * Number of minutes timetable ids are cached for.
     */
    const TIMETABLE_IDS_CACHE_TIME = 2880;
    /**
     * Number of weeks to fetch after this week.
     */
    const FETCH_NEXT_WEEKS = 7;
    /**
     * Version of timetable fetcher.
     */
    const VERSION = '0.3';
    /**
     * Timetable type for students.
     */
    const TYPE_STUDENT = 1;
    /**
     * Timetable type for teachers.
     */
    const TYPE_TEACHER = 2;
    /**
     * Element type containing information about a group.
     */
    const ELEMENT_TYPE_GROUP = 1;
    /**
     * Element type containing information about a teacher.
     */
    const ELEMENT_TYPE_TEACHER = 2;
    /**
     * Element type containing information about a class.
     */
    const ELEMENT_TYPE_CLASS = 3;
    /**
     * Element type containing information about a location.
     */
    const ELEMENT_TYPE_LOCATION = 4;

    /**
     * Generates DateTime object from date and time string.
     *
     * @param $date string date string formatted YYYYmmdd
     * @param $time string time string formatted (h)hmm
     *
     * @return DateTime the generated object
     */
    private static function timeToDate($date, $time)
    {
        $d    = DateTime::createFromFormat('Ymd', $date);
        $time = intval($time);

        $h = floor($time / 100);
        $m = $time % 100;

        $d->setTime($h, $m);

        return $d;
    }

    /**
     * Find object with given id
     *
     * @param $data array
     * @param $id   int
     *
     * @return object
     */
    private static function getElementById($data, $id)
    {
        foreach ($data as $el) if ($el->id == $id) return $el;

        return null;
    }

    /**
     * Generates string representing this group element.
     *
     * @param $el object the element
     *
     * @return string a string representing this element
     */
    private static function elementToGroup($el)
    {
        return $el->displayname;
    }

    /**
     * Generates string representing this teacher element.
     *
     * @param $el object the element
     *
     * @return string representing element
     */
    private static function elementToTeacher($el)
    {
        return $el->displayname;
    }

    /**
     * Generates string representing this class element.
     *
     * @param $el object the element
     *
     * @return string representing element
     */
    private static function elementToClass($el)
    {
        return $el->displayname;
    }

    /**
     * Generates Location representing this location element.
     *
     * @param $el object the element
     *
     * @return Location representing element
     */
    private static function elementToLocation($el)
    {
        return with(new Location)->setName($el->displayname);
    }

    /**
     * generates an calendar (.ics) file for the given timetable entry.
     *
     * @param       $id      int the id of the timetable
     * @param       $type    int the type of the timetable
     * @param       $name    string name of the timetable
     * @param array $filters a list of events (lessons) to ignore in the timetable
     *
     * @return string the calendar file as text
     * @throws Exception if the request to WebUntis fails, an exception is thrown
     */
    static function fetch($id, $type, $name, $filters = array())
    {
        /*
         * Validate the function's parameters.
         */
        $id      = intval($id);
        $type    = intval($type);
        $name    = strval($name);
        $filters = is_array($filters) ? $filters : array();

        /*
         * Initialize a calendar,
         * set the timezone of the calendar for the calendar software to use,
         * set the name of the calendar based on the name given in as a parameter,
         * tell the calendar software the lifecycle of the calendar is one hour and
         * set the productId to this generator.
         */
        $calendar = new Calendar();
        $calendar->setTimezone(new DateTimeZone("Europe/Amsterdam"));
        $calendar->addCustomHeader('X-WR-CALNAME', "Rooster $name");
        $calendar->addCustomHeader('X-PUBLISHED-TTL', 'PT1H');
        $calendar->setProdId('-//Tim Potze//CalendarUntis ' . self::VERSION . '//EN');

        /*
         * Timetables are fetched per-week. Here we generate the date of the first day of this week.
         * Every iteration(or week) we add 7 days to this date to cycle trough the weeks we want to fetch.
         */
        $date = with(new DateTime)->setTimestamp(strtotime('this week', time()));

        for ($w = 0; $w <= self::FETCH_NEXT_WEEKS; $w++)
        {
            /*
            * Generate a cache key based on the data to be requested and check the cache for this key.
            */
            $key = "wt.$id.$type." . $date->format('Y-m-d');

            if (Cache::has($key))
            {
                $data = Cache::get($key);
            }
            else
            {
                \Log::notice("Fetching timetable for $key...");
                /*
                 * Request the timetable for this week's date.
                 */
                $request = new Request(School::URL);
                $request->setOption(CURLOPT_POST, true);
                $request->setOption(CURLOPT_POSTFIELDS, School::getWeeklyTimetableFields($type, $id, $date));
                $request->setOption(CURLOPT_COOKIE, School::COOKIES); /* Cookies contain information about the school */
                $request->execute();

                /*
                 * Check for successful response.
                 */
                if (!$request->isSuccessful()) throw new Exception($request->getErrorMessage());

                /*
                 * Parse the response as a json object and get the result.data field and
                 * store this date in the cache for TIMETABLE_CACHE_TIME minutes.
                 */
                $weekJson = json_decode($request->getResponse()->getContent());

                if(!is_object($weekJson) || !is_object($weekJson->result)) {
                    continue;
                }
                $data = $weekJson->result->data;
                Cache::put($key, $data, self::TIMETABLE_CACHE_TIME);
            }
            /*
             * A calendar can contain multiple elements.
             * For each of these elements add all periods to the calendar.
             */
            foreach ($data->elementIds as $timeTableElementId)
            {
                /*
                 * Create an array in which we can later filter sequential events to form one longer event.
                 * Structure: $events[DATE][index] = Event
                 */
                $events = [];

                /*
                 * Loop trough all periods in the periods list for this element.
                 */
                foreach ($data->elementPeriods->$timeTableElementId as $period)
                {
                    /*
                     * Create a CalendarEvent based on the dates and the id of the period.
                     */
                    $event = with(new CalendarEvent)->setStart(self::timeToDate($period->date, $period->startTime))
                             ->setEnd(self::timeToDate($period->date, $period->endTime))->setUid($period->id);

                    /*
                     * Initialize empty string for the teacher, group and class.
                     * These might be filled when looping trough the elements for this period.
                     */
                    $teacher = '';
                    $group   = '';
                    $class   = '';

                    /*
                     * Loop trough the elements of this period. A period-element can contain information about
                     * the group, teacher, class or location.
                     */
                    foreach ($period->elements as $elementData)
                    {
                        /*
                         * Get the element from the elements section of the JSON-data based
                         * on the Id of the period-element.
                         */
                        $element = self::getElementById($data->elements, $elementData->id);

                        switch ($elementData->type)
                        {
                            case self::ELEMENT_TYPE_GROUP:
                                $group = self::elementToGroup($element);
                                break;
                            case self::ELEMENT_TYPE_TEACHER:
                                $teacher = self::elementToTeacher($element);
                                break;
                            case self::ELEMENT_TYPE_CLASS:
                                $class = self::elementToClass($element);
                                break;
                            case self::ELEMENT_TYPE_LOCATION:
                                $event->addLocation(self::elementToLocation($element));
                                break;
                        }
                    }

                    /*
                     * Set the event's summary based on the provided lessonText.
                     */
                    $lessonText = trim($period->lessonText);
                    if (!empty($lessonText))
                    {
                        $event->setSummary($lessonText);
                        $event->setDescription(trim("$class $teacher $group"));
                    }
                    else
                    {
                        /*
                         * Skip classless hours.
                         */
                        if(empty($class)) continue;

                        $event->setSummary($class);
                        $event->setDescription(trim("$teacher $group"));
                    }

                    /*
                     * Filter unwanted classes from the calendar.
                     */
                    $filtered = false;

                    foreach ($filters as $filter)
                    {
                        if (strpos(strtolower($event->getSummary()), strtolower(trim($filter))) !== false)
                            $filtered = true;
                    }

                    if ($filtered) continue;

                    /*
                     * Add the event to the list of events.
                     */
                    if (!array_key_exists($period->date, $events)) $events[$period->date] = [];
                    $events[$period->date][] = $event;
                }

                /*
                 * Merge sequential events.
                 *
                 * Loop trough every day of the week with events.
                 */
                foreach ($events as $eventsToday)
                {
                    /*
                     * Sort today's events based on the startdate of the event.
                     */
                    usort($eventsToday, function ($a, $b)
                    {
                        if ($a->getStart() == $b->getStart()) return 0;
                        if ($a->getStart() < $b->getStart()) return -1;
                        else return 1;
                    });

                    /*
                     * Loop trough every event(i), starting at the end of the array.
                     */
                    for ($i = count($eventsToday) - 1; $i > 0; $i--)
                    {
                        /*
                         * Match the current event with every previous event(j) of the current day.
                         */
                        for ($j = $i - 1; $j >= 0; $j--)
                        {
                            /*
                             * If (i's startime and j's endtime are equal [i proceeds j]) and
                             * (i and j's sumaries are equal) and (i and j's descriptions are equal).
                             */
                            if ($eventsToday[$i]->getStart() == $eventsToday[$j]->getEnd() &&
                                $eventsToday[$i]->getSummary() == $eventsToday[$j]->getSummary() &&
                                $eventsToday[$i]->getDescription() == $eventsToday[$j]->getDescription()
                            )
                            {
                                /*
                                 * Set j's endtime to i's endtime, remove event i from the list and
                                 * stop looking for and event preceding i.
                                 */
                                $eventsToday[$j]->setEnd($eventsToday[$i]->getEnd());
                                unset($eventsToday[$i]);
                                break;
                            }
                        }
                    }

                    /*
                     * Add all events to the calendar
                     */
                    foreach ($eventsToday as $e) $calendar->addEvent($e);
                }
            }

            /*
             * Increase the date by 7 days for the next fetch iteration.
             */
            $date->add(new DateInterval('P7D'));
        }

        /*
         * Export the calendar and return it.
         */
        $data = with(new CalendarExport(new CalendarStream, new Formatter()))->addCalendar($calendar)->getStream();

        return $data;
    }

    /**
     * Fetch an array of timetable ids.
     *
     * @return array
     * @throws Exception if the request to WebUntis fails, an exception is thrown
     */
    static function fetchAllTimetableIds()
    {
        return array_merge(self::fetchTimetableIds(), self::fetchTimetableIds(self::TYPE_TEACHER));
    }

    /**
     * Fetch an array of timetable ids of the given type.
     *
     * @param int $type type
     *
     * @return array
     * @throws Exception if the request to WebUntis fails, an exception is thrown
     */
    static function fetchTimetableIds($type = self::TYPE_STUDENT)
    {
        /*
         * Validate the function's parameters.
         */
        $type = intval($type);

        /*
         * Generate a cache key based on the parameters and check the cache for any entries.
         */
        $key = "ttids.$type";
        if (Cache::has($key)) return Cache::get($key);

        //https://roosters.windesheim.nl/WebUntis/jsonrpc_web/jsonCalendarService
        
//        $request = new Request("https://roosters.windesheim.nl/WebUntis/jsonrpc_web/jsonCalendarService");
//        $request->setOption(CURLOPT_POST, true);
//        $request->setOption(CURLOPT_POSTFIELDS, School::getPageConfigFields($type));
//        $request->setOption(CURLOPT_COOKIE, School::COOKIES);
//        $dateRequest = $request->execute();
//        dd($request->getResponse()->headers->getCookies());
		

        /*
         * At this point we know there is no cache entry for this pageconfig.
         * Therefore we need to recache the pageconfig.
         *
         * Request the timetable for this week's date.
         */
        $request = new Request(School::URL);
        $request->setOption(CURLOPT_POST, true);
        $request->setOption(CURLOPT_POSTFIELDS, School::getPageConfigFields($type));
        $request->setOption(CURLOPT_COOKIE, School::COOKIES);
        $request->execute(); /* Cookies contain information about the school */

        /*
         * Check for successful response.
         */
        if (!$request->isSuccessful()) throw new Exception($request->getErrorMessage());

        /*
         * Cache the response for two days and return it.
         */
        $result = json_decode($request->getResponse()->getContent())->elements;
        foreach ($result as $element) $element->type = $type;

        Cache::put($key, $result, self::TIMETABLE_IDS_CACHE_TIME);

        return $result;
    }
}
