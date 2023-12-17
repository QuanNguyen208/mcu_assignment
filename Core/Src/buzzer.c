/*
 * buzzer.c
 *
 *  Created on: Nov 18, 2023
 *      Author: Admin
 */

#include "buzzer.h"

void fsm_Buzzer() {
    if (pedestrian_light_state == WORK && row_traffic_light_state == RED_AUTO) {
        switch (buzzer_state) {
            case ON:
                /* Turn on Buzzer */
                if (timer4Flag == 1) {
                    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 999);
                    buzzer_state = OFF;
                    setTimer4(Time_duration * TICK);
                }
                break;
            case OFF:
                if (timer4Flag == 1) {
                    buzzer_state = ON;
                    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
                    setTimer4(remain_row_light_time);
                }
                break;
            default:
                break;
        }
    } else {
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
    }
}

