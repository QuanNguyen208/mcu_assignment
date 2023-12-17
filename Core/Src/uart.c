/*
 * uart.c
 *
 *  Created on: Nov 18, 2023
 *      Author: Admin
 */

#include "uart.h"

void uart_transmit(){
	switch(row_traffic_light_state){
		case RED_AUTO:
		case GREEN_AUTO:
		case YEL_AUTO:
		case RED_MANUAL:
		case GREEN_MANUAL:
		case YEL_MANUAL:
			if (remain_row_light_time < 10) HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "!7SEG:0%d#", remain_row_light_time), 1000);
			else HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "!7SEG:%d#", remain_row_light_time), 1000);
			break;
		case RED_SET:
		case GREEN_SET:
		case YEL_SET:
			if (Set_TL_Time < 10) HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "!7SEG:0%d#", Set_TL_Time), 1000);
			else HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "!7SEG:%d#", Set_TL_Time), 1000);
			break;
		default:
			break;
	}
}
