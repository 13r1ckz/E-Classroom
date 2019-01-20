<?php namespace Calendar;

use DateTime;

class School
{
    const COOKIES       = 'schoolname="_d2luZGVzaGVpbQ=="';
    const DEPARTMENT_ID = '0';
    const FILTER_TYPE   = '-2';
    const FORMAT_ID     = '6';
    const URL           = 'https://roostertest.windesheim.nl/WebUntis/Timetable.do';
    //const URL           = 'https://asopo.webuntis.com/WebUntis/Timetable.do';

    /**
     * Generate the postfields to send for a weekly timetable request.
     *
     * @param int      $type type of the timetable to fetch
     * @param int      $id   id of the timetable to fetch
     * @param DateTime $date date of the week for which to fetch the timetable
     *
     * @return array fields
     */
    static function getWeeklyTimetableFields($type, $id, $date)
    {
        return [
            'ajaxCommand'  => 'getWeeklyTimetable',
            'date'         => $date->format('Ymd'),
            'departmentId' => self::DEPARTMENT_ID,
            'elementType'  => $type,
            'elementId'    => $id,
            'filter'       => self::FILTER_TYPE,
            'formatId'     => self::FORMAT_ID
        ];
    }

    /**
     * Generate the postfields to send for a timetables list.
     *
     * @param $type type of the timetables list
     *
     * @return array fields
     */
    static function getPageConfigFields($type)
    {
        return [
            'ajaxCommand' => 'getPageConfig',
            'type'        => $type,
            'filter'      => self::FILTER_TYPE
        ];
    }
}