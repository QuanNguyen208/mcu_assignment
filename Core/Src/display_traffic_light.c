/*
 * display_traffic_light.c
 *
 *  Created on: Nov 7, 2023
 *      Author: Admin
 */

#include "display_traffic_light.h"

void display_traffic_light(){
	switch (row_traffic_light_state){
	case RED_AUTO:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, RESET);
		break;
	case RED_MANUAL:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, RESET);
		break;
	case RED_SET:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, RESET);
		HAL_GPIO_WritePin(TL2_SIGNAL1_GPIO_Port, TL2_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL2_SIGNAL2_GPIO_Port, TL2_SIGNAL2_Pin, RESET);
		break;
	case GREEN_AUTO:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, RESET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, SET);
		break;
	case GREEN_MANUAL:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, RESET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, SET);
		break;
	case GREEN_SET:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, RESET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, SET);
		HAL_GPIO_WritePin(TL2_SIGNAL1_GPIO_Port, TL2_SIGNAL1_Pin, RESET);
		HAL_GPIO_WritePin(TL2_SIGNAL2_GPIO_Port, TL2_SIGNAL2_Pin, SET);
		break;
	case YEL_AUTO:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, SET);
		break;
	case YEL_MANUAL:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, SET);
		break;
	case YEL_SET:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, SET);
		HAL_GPIO_WritePin(TL2_SIGNAL1_GPIO_Port, TL2_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL2_SIGNAL2_GPIO_Port, TL2_SIGNAL2_Pin, SET);
		break;
	default:
		HAL_GPIO_WritePin(TL1_SIGNAL1_GPIO_Port, TL1_SIGNAL1_Pin, RESET);
		HAL_GPIO_WritePin(TL1_SIGNAL2_GPIO_Port, TL1_SIGNAL2_Pin, RESET);
	}

	switch (cow_traffic_light_state){
	case RED_AUTO:
		HAL_GPIO_WritePin(TL2_SIGNAL1_GPIO_Port, TL2_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL2_SIGNAL2_GPIO_Port, TL2_SIGNAL2_Pin, RESET);
		break;
	case RED_MANUAL:
		HAL_GPIO_WritePin(TL2_SIGNAL1_GPIO_Port, TL2_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL2_SIGNAL2_GPIO_Port, TL2_SIGNAL2_Pin, RESET);
		break;
	case GREEN_AUTO:
		HAL_GPIO_WritePin(TL2_SIGNAL1_GPIO_Port, TL2_SIGNAL1_Pin, RESET);
		HAL_GPIO_WritePin(TL2_SIGNAL2_GPIO_Port, TL2_SIGNAL2_Pin, SET);
		break;
	case GREEN_MANUAL:
		HAL_GPIO_WritePin(TL2_SIGNAL1_GPIO_Port, TL2_SIGNAL1_Pin, RESET);
		HAL_GPIO_WritePin(TL2_SIGNAL2_GPIO_Port, TL2_SIGNAL2_Pin, SET);
		break;
	case YEL_AUTO:
		HAL_GPIO_WritePin(TL2_SIGNAL1_GPIO_Port, TL2_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL2_SIGNAL2_GPIO_Port, TL2_SIGNAL2_Pin, SET);
		break;
	case YEL_MANUAL:
		HAL_GPIO_WritePin(TL2_SIGNAL1_GPIO_Port, TL2_SIGNAL1_Pin, SET);
		HAL_GPIO_WritePin(TL2_SIGNAL2_GPIO_Port, TL2_SIGNAL2_Pin, SET);
		break;
	default:
		break;
	}
}
