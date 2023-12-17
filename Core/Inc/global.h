/*
 * global.h
 *
 *  Created on: Nov 7, 2023
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "button_reading.h"
#include "fsm_traffic_light.h"
#include "timer.h"
#include "display_traffic_light.h"
#include "fsm_pedestrian.h"
#include "stdlib.h"
#include <stdio.h>
#include "string.h"
#include "buzzer.h"
#include "uart.h"

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart2;

char str[30];

//Timer//
#define TICK	1
int timer1_count;
int timer1Flag;

int timer2_count;
int timer2Flag;

int timer3_count;
int timer3Flag;

int timer4_count;
int timer4Flag;

int timer5_count;
int timer5Flag;


//BUTTON
#define num_of_buttons		4
uint16_t INPUT_BUTTON[num_of_buttons];
uint8_t pressedButton_flag[num_of_buttons];

#define NORMAL_BUTTON 		0
#define PRESS_BUTTON 		1
#define LONG_PRESS_BUTTON 	2

//Light time//

int red_time;
int green_time;
int yellow_time;

int remain_row_light_time;
int remain_col_light_time;

int TIMER3_PEDESTRIAN_CYCLE;

#define TIMER1_SECOND_DURATION 		100  // 1s
#define TIMER1_10SECOND_DURATION 	1000 // 10s

//FSM
int button_state;
int row_traffic_light_state;
int cow_traffic_light_state;
int pedestrian_light_state;

#define RED_AUTO		0
#define GREEN_AUTO		1
#define YEL_AUTO		2
#define RED_MANUAL		3
#define GREEN_MANUAL 	4
#define YEL_MANUAL 		5
#define FORCE_STOP		6
#define RED_SET			7
#define GREEN_SET		8
#define YEL_SET			9
#define NORMAL			0
#define WORK			1

//Buzzer
int buzzer_state;
int increase_frequency;
int increase_speed;
#define ON	1
#define OFF 0
#define Time_duration 10 //buzzer on in 100ms



int Set_TL_Time;
#endif /* INC_GLOBAL_H_ */
