
#include <ets_sys.h>
#include <osapi.h>
#include <os_type.h>


//C Library's
extern "C"{
	#include "user_interface.h"
	#include <gpio.h>

	void ets_timer_disarm(ETSTimer *ptimer);
	void ets_timer_setfn(ETSTimer *ptimer, ETSTimerFunc *pfunction, void *parg);
	void ets_timer_arm_new(ETSTimer *ptimer,uint32_t milliseconds, bool repeat_flag, bool);

	// see eagle_soc.h for these definitions
	#define LED_GPIO 2
	#define LED_GPIO_MUX PERIPHS_IO_MUX_GPIO2_U
	#define LED_GPIO_FUNC FUNC_GPIO2

	#define DELAY 500 /* milliseconds */
}

LOCAL os_timer_t blink_timer;
LOCAL uint8_t led_state=0;

LOCAL void ICACHE_FLASH_ATTR blink_cb(void *arg){
	GPIO_OUTPUT_SET(LED_GPIO, led_state);
	led_state ^=1;
}

/******************************************************************************
 * FunctionName : user_rf_cal_sector_set
 * Description  : SDK just reversed 4 sectors, used for rf init data and paramters.
 *                We add this function to force users to set rf cal sector, since
 *                we don't know which sector is free in user's application.
 *                sector map for last several sectors : ABBBCDDD
 *                A : rf cal
 *                B : at parameters
 *                C : rf init data
 *                D : sdk parameters
 * Parameters   : none
 * Returns      : rf cal sector
*******************************************************************************/
extern "C" uint32 ICACHE_FLASH_ATTR user_rf_cal_sector_set(void){
    enum flash_size_map size_map = system_get_flash_size_map();
    uint32 rf_cal_sec = 0;

    switch (size_map) {
        case FLASH_SIZE_4M_MAP_256_256:
            rf_cal_sec = 128 - 8;
            break;

        case FLASH_SIZE_8M_MAP_512_512:
            rf_cal_sec = 256 - 5;
            break;

        case FLASH_SIZE_16M_MAP_512_512:
        case FLASH_SIZE_16M_MAP_1024_1024:
            rf_cal_sec = 512 - 5;
            break;

        case FLASH_SIZE_32M_MAP_512_512:
        case FLASH_SIZE_32M_MAP_1024_1024:
            rf_cal_sec = 1024 - 5;
            break;

        default:
            rf_cal_sec = 0;
            break;
    }

    return rf_cal_sec;
}

void ICACHE_FLASH_ATTR user_rf_pre_init(void){
}

extern "C" void ICACHE_FLASH_ATTR user_init(void){
	// Configure pin as a GPIO
	PIN_FUNC_SELECT(LED_GPIO_MUX, LED_GPIO_FUNC);
	// Set up a timer to blink the LED
	// os_timer_disarm(ETSTimer *ptimer)
	os_timer_disarm(&blink_timer);
	// os_timer_setfn(ETSTimer *ptimer, ETSTimerFunc *pfunction, void *parg)
	os_timer_setfn(&blink_timer, (os_timer_func_t *)blink_cb, (void *)0);
	// void os_timer_arm(ETSTimer *ptimer,uint32_t milliseconds, bool repeat_flag)
	os_timer_arm(&blink_timer, DELAY, 1);
}
