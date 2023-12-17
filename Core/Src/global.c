/*
 * global.c
 *
 *  Created on: Nov 7, 2023
 *      Author: Admin
 */

#include "global.h"

//BUTTON

uint8_t pressedButton_flag[num_of_buttons] = {0,0,0,0};
uint16_t INPUT_BUTTON[num_of_buttons] = {BUTTON_MOD_Pin, BUTTON_IC_Pin, BUTTON_SET_Pin, BUTTON_PEDE_Pin};
//FSM

int button_state = NORMAL_BUTTON;
int row_traffic_light_state = RED_AUTO;
int cow_traffic_light_state = GREEN_AUTO;
int pedestrian_light_state = NORMAL;

//Buzzer

int buzzer_state = OFF;
int increase_frequency = 99;
int increase_speed = 5;

//Timer

int timer1_count = 0;
int timer1Flag = 0;
int timer2_count = 0;
int timer2Flag = 0;
int timer3_count = 0;
int timer3Flag = 0;
int timer4_count = 0;
int timer4Flag = 0;

//Light time
int red_time = 5;
int green_time = 3;
int yellow_time = 2;
int remain_row_light_time = 5;
int remain_col_light_time = 3;
int Set_TL_Time = 0;

//Pedestrian mode time

int TIMER3_PEDESTRIAN_CYCLE = 1000;
