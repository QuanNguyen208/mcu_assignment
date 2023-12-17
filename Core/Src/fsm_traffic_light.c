/*
 * fsm_traffic_light.c
 *
 *  Created on: Nov 7, 2023
 *      Author: Admin
 */


#include "fsm_traffic_light.h"

int To_Default_State = 0;        // used to set COL traffic state

void ResetButtonState(){        // reset buttons
    for(int i = 0; i < num_of_buttons; i++){
        pressedButton_flag[i] = 0;
    }
}

void changeTime(){                // change traffic time
    Set_TL_Time++;
    if(Set_TL_Time >= 100){
        Set_TL_Time = 1;
    }
}

void fsm_row_traffic_light(){
    switch (row_traffic_light_state) {
    /* AUTO MODE */
    case RED_AUTO:
        if(timer1Flag == 1){
            /* Count down time */
            remain_row_light_time--;
            if(remain_row_light_time == 0){
                /* Move to next state */
                row_traffic_light_state = GREEN_AUTO;
                remain_row_light_time = green_time;
            }

            uart_transmit();
            setTimer1(TIMER1_SECOND_DURATION * TICK);
        }
        /* Check if button 0 is pressed --> move to SET_MODE */
        if(pressedButton_flag[0]){
            pressedButton_flag[0] = 0;
            Set_TL_Time = red_time;
            row_traffic_light_state = RED_SET;
            cow_traffic_light_state = FORCE_STOP;
            uart_transmit();
            setTimer1(TIMER1_10SECOND_DURATION * TICK);
            ResetButtonState();
        }
        /* Check if button 1 is pressed --> move to RED_MANUAL */
        if(pressedButton_flag[1]){
            pressedButton_flag[1] = 0;
            row_traffic_light_state = RED_MANUAL;
            cow_traffic_light_state = GREEN_MANUAL;
            ResetButtonState();
        }
        break;
    case GREEN_AUTO:
        if(timer1Flag == 1){
            /* Count down time */
            remain_row_light_time--;
            if(remain_row_light_time == 0){
                /* Move to next state */
                row_traffic_light_state = YEL_AUTO;
                remain_row_light_time = yellow_time;
            }
            uart_transmit();
            setTimer1(TIMER1_SECOND_DURATION * TICK);
        }
        /* Check if button 0 is pressed --> move to SET_MODE */
        if(pressedButton_flag[0]){
            pressedButton_flag[0] = 0;
            Set_TL_Time = red_time;
            row_traffic_light_state = RED_SET;
            cow_traffic_light_state = FORCE_STOP;
            uart_transmit();
            setTimer1(TIMER1_10SECOND_DURATION * TICK);
            ResetButtonState();
        }
        /* Check if button 1 is pressed --> move to RED_MANUAL */
        if(pressedButton_flag[1]){
            pressedButton_flag[1] = 0;
            row_traffic_light_state = RED_MANUAL;
            cow_traffic_light_state = GREEN_MANUAL;
            ResetButtonState();
        }
        break;
    case YEL_AUTO:
        if(timer1Flag == 1){
            /* Count down time */
            remain_row_light_time--;
            if(remain_row_light_time == 0){
                /* Move to next state*/
                row_traffic_light_state = RED_AUTO;
                remain_row_light_time = red_time;
            }
            uart_transmit();
            setTimer1(TIMER1_SECOND_DURATION * TICK);
        }
        /* Check if button 0 is pressed --> move to SET_MODE */
        if(pressedButton_flag[0]){
            pressedButton_flag[0] = 0;
            Set_TL_Time = red_time;
            row_traffic_light_state = RED_SET;
            cow_traffic_light_state = FORCE_STOP;
            uart_transmit();
            setTimer1(TIMER1_10SECOND_DURATION * TICK);
            ResetButtonState();
        }
        /* Check if button 1 is pressed --> move to RED_MANUAL */
        if(pressedButton_flag[1]){
            pressedButton_flag[1] = 0;
            row_traffic_light_state = RED_MANUAL;
            cow_traffic_light_state = GREEN_MANUAL;
            ResetButtonState();
        }
        break;

    /* SET MODE */
    case RED_SET:
        if(timer1Flag == 1){
            /* Back to AUTO MODE */
            row_traffic_light_state = RED_AUTO;
            remain_row_light_time = red_time;
            To_Default_State = 1;
            uart_transmit();
            setTimer1(TIMER1_SECOND_DURATION * TICK);
            break;
        }
        if(pressedButton_flag[0]){
            /* Move to next state if button 0 is pressed */
            pressedButton_flag[0] = 0;
            Set_TL_Time = green_time;
            row_traffic_light_state = GREEN_SET;
            uart_transmit();
            setTimer1(TIMER1_10SECOND_DURATION * TICK);
        }
        if(pressedButton_flag[1]){
            /* INC. time if button 1 is pressed */
            pressedButton_flag[1] = 0;
            changeTime();
            uart_transmit();
            setTimer1(TIMER1_10SECOND_DURATION * TICK);
        }
        if(pressedButton_flag[2]){
            /* Save value */
            pressedButton_flag[2] = 0;
            red_time = Set_TL_Time;
            TIMER3_PEDESTRIAN_CYCLE = (red_time + yellow_time + green_time) * TIMER1_SECOND_DURATION;
            setTimer1(TIMER1_10SECOND_DURATION * TICK);
        }
        break;
    case GREEN_SET:
        if(timer1Flag == 1){
            /* Back to AUTO MODE */
            row_traffic_light_state = RED_AUTO;
            To_Default_State = 1;
            remain_row_light_time = red_time;
            uart_transmit();
            setTimer1(TIMER1_SECOND_DURATION * TICK);
            break;
        }
        if(pressedButton_flag[0]){
            /* Move to next state if button 0 is pressed */
            pressedButton_flag[0] = 0;
            Set_TL_Time = yellow_time;
            row_traffic_light_state = YEL_SET;
            uart_transmit();
            setTimer1(TIMER1_10SECOND_DURATION * TICK);
        }
        if(pressedButton_flag[1]){
            /* INC. time if button 1 is pressed */
            pressedButton_flag[1] = 0;
            changeTime();
            uart_transmit();
            setTimer1(TIMER1_10SECOND_DURATION * TICK);
        }
        if(pressedButton_flag[2]){
            /* Save value if button 2 is pressed*/
            pressedButton_flag[2] = 0;
            green_time = Set_TL_Time;
            TIMER3_PEDESTRIAN_CYCLE = (red_time + yellow_time + green_time) * TIMER1_SECOND_DURATION;
            setTimer1(TIMER1_10SECOND_DURATION * TICK);
        }
        break;
    case YEL_SET:
        if(timer1Flag == 1){
            /* Back to AUTO MODE */
            row_traffic_light_state = RED_AUTO;
            To_Default_State = 1;
            remain_row_light_time = red_time;
            uart_transmit();
            setTimer1(TIMER1_SECOND_DURATION * TICK);
            break;
        }
        if(pressedButton_flag[0]){
            /* Move to next state if button 0 is pressed */
            pressedButton_flag[0] = 0;
            Set_TL_Time = red_time;
            remain_row_light_time = red_time;
            To_Default_State = 1;
            row_traffic_light_state = RED_AUTO;
            uart_transmit();

            setTimer1(TIMER1_SECOND_DURATION * TICK);
        }
        if(pressedButton_flag[1]){
            /* INC. time if button 1 is pressed */
            pressedButton_flag[1] = 0;
            changeTime();
            uart_transmit();
            setTimer1(TIMER1_10SECOND_DURATION * TICK);
        }
        if(pressedButton_flag[2]){
            /* Save value if button 2 is pressed */
            pressedButton_flag[2] = 0;
            yellow_time = Set_TL_Time;
            TIMER3_PEDESTRIAN_CYCLE = (red_time + yellow_time + green_time) * TIMER1_SECOND_DURATION;
            setTimer1(TIMER1_10SECOND_DURATION * TICK);
        }
        break;

    /* MANUAL MODE */
    case RED_MANUAL:
        if(pressedButton_flag[1]){
            /* Move to next state of MANUAL MODE if button 1 is pressed */
            uart_transmit();
            pressedButton_flag[1] = 0;
            row_traffic_light_state = GREEN_MANUAL;
            cow_traffic_light_state = RED_MANUAL;
            ResetButtonState();
        }
        if(pressedButton_flag[0]){
            /* Back to RED_AUTO */
            pressedButton_flag[0] = 0;
            Set_TL_Time = red_time;
            remain_row_light_time = red_time;
            To_Default_State = 1;
            row_traffic_light_state = RED_AUTO;
            cow_traffic_light_state = FORCE_STOP;
            uart_transmit();
            setTimer1(TIMER1_SECOND_DURATION * TICK);
        }
        break;
    case GREEN_MANUAL:
        if(pressedButton_flag[1]){
            /* Move to next state of MANUAL MODE if button 1 is pressed */
            uart_transmit();
            pressedButton_flag[1] = 0;
            row_traffic_light_state = YEL_MANUAL;
            cow_traffic_light_state = YEL_MANUAL;
            ResetButtonState();
        }
        if(pressedButton_flag[0]){
            /* BACK TO RED_AUTO */
            pressedButton_flag[0] = 0;
            Set_TL_Time = red_time;
            remain_row_light_time = red_time;
            To_Default_State = 1;
            row_traffic_light_state = RED_AUTO;
            cow_traffic_light_state = FORCE_STOP;
            uart_transmit();
            setTimer1(TIMER1_SECOND_DURATION * TICK);
        }
        break;
    case YEL_MANUAL:
        if(pressedButton_flag[1]){
            /* Move to next state of MANUAL MODE if button 1 is pressed */
            uart_transmit();
            pressedButton_flag[1] = 0;
            row_traffic_light_state = RED_MANUAL;
            cow_traffic_light_state = GREEN_MANUAL;
            ResetButtonState();
        }
        if(pressedButton_flag[0]){
            /* BACK TO RED_AUTO */
            pressedButton_flag[0] = 0;
            Set_TL_Time = red_time;
            remain_row_light_time = red_time;
            To_Default_State = 1;
            row_traffic_light_state = RED_AUTO;
            cow_traffic_light_state = FORCE_STOP;
            uart_transmit();
            setTimer1(TIMER1_SECOND_DURATION * TICK);
        }
        break;
    default:
        break;
    }
}

void fsm_col_traffic_light(){
    if(timer2Flag == 1){
        remain_col_light_time--;

        switch (cow_traffic_light_state) {
            case RED_AUTO:
                if (remain_col_light_time == 0) {
                    cow_traffic_light_state = GREEN_AUTO;
                    remain_col_light_time = green_time;
                }
                break;

            case GREEN_AUTO:
                if (remain_col_light_time == 0) {
                    cow_traffic_light_state = YEL_AUTO;
                    remain_col_light_time = yellow_time;
                }
                break;

            case YEL_AUTO:
                if (remain_col_light_time == 0) {
                    cow_traffic_light_state = RED_AUTO;
                    remain_col_light_time = red_time;
                }
                break;

            case FORCE_STOP:
                /* Trap state to force Col stop */
                if (To_Default_State == 1) {
                    To_Default_State = 0;
                    cow_traffic_light_state = GREEN_AUTO;
                    remain_col_light_time = green_time;
                }
                break;

            default:
                break;
        }

        setTimer2(TIMER1_SECOND_DURATION * TICK);
    }
}


