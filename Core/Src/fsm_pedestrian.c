 /*
 * fsm_pedestrian_light.c
 *
 *  Created on: Nov 8, 2023
 *      Author: Admin
 */

#include "fsm_pedestrian.h"

void fsm_pedestrian_light() {
    switch (pedestrian_light_state) {
        /* NORMAL MODE */
        case NORMAL:
            /* RESET PEDESTRIAN LIGHT */
            HAL_GPIO_WritePin(PEDE_SIGNAL1_GPIO_Port, PEDE_SIGNAL1_Pin, RESET);
            HAL_GPIO_WritePin(PEDE_SIGNAL2_GPIO_Port, PEDE_SIGNAL2_Pin, RESET);

            /* PEDESTRIAN BUTTON IS PRESSED -> into WORK MODE */
            if (pressedButton_flag[3]) {
                pressedButton_flag[3] = 0;
                pedestrian_light_state = WORK;
                buzzer_state = ON;
                setTimer4(1 * TICK);                                  // buzzer timer
                setTimer3(2 * TIMER3_PEDESTRIAN_CYCLE * TICK);        // pedestrian mode timer, set to 2 cycles of RED + YELLOW + GREEN
            }
            break;

        /* WORK MODE */
        case WORK:
            if (timer3Flag == 1 || row_traffic_light_state == GREEN_SET
                || row_traffic_light_state == RED_SET || row_traffic_light_state == YEL_SET
                || row_traffic_light_state == RED_MANUAL || row_traffic_light_state == YEL_MANUAL
                || row_traffic_light_state == GREEN_MANUAL) {    // 2 cycles passed without pressing the button or MODE changed to SET or MANUAL
                pedestrian_light_state = NORMAL;
                break;
            }

            if (pressedButton_flag[3]) {    // the button is pressed before timeout
                setTimer3(2 * TIMER3_PEDESTRIAN_CYCLE * TICK);
            }

            /* Turn on Pedestrian Light */
            switch (cow_traffic_light_state) {
                case RED_AUTO:
                    HAL_GPIO_WritePin(PEDE_SIGNAL1_GPIO_Port, PEDE_SIGNAL1_Pin, SET);
                    HAL_GPIO_WritePin(PEDE_SIGNAL2_GPIO_Port, PEDE_SIGNAL2_Pin, RESET);
                    break;
                case GREEN_AUTO:
                    HAL_GPIO_WritePin(PEDE_SIGNAL1_GPIO_Port, PEDE_SIGNAL1_Pin, RESET);
                    HAL_GPIO_WritePin(PEDE_SIGNAL2_GPIO_Port, PEDE_SIGNAL2_Pin, SET);
                    break;
                case YEL_AUTO:
                    HAL_GPIO_WritePin(PEDE_SIGNAL1_GPIO_Port, PEDE_SIGNAL1_Pin, SET);
                    HAL_GPIO_WritePin(PEDE_SIGNAL2_GPIO_Port, PEDE_SIGNAL2_Pin, SET);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}
