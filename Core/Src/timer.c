/*
 * timer.c
 *
 *  Created on: Nov 7, 2023
 *      Author: Admin
 */


#include "timer.h"

void setTimer1(int duration){             // first traffic light
	timer1_count = duration/TICK;
	timer1Flag = 0;
}
void setTimer2(int duration){            // second traffic light
	timer2_count = duration/TICK;
	timer2Flag = 0;
}
void setTimer3(int duration){            // pedestrian light timer
	timer3_count = duration/TICK;
	timer3Flag = 0;
}
void setTimer4(int duration){            // buzzer timer
	timer4_count = duration/TICK;
	timer4Flag = 0;
}
void setTimer5(int duration){            // extra timer
    timer5_count = duration/TICK;
    timer5Flag = 0;
}
// Run all timer
void timerRun(){
	if(timer1_count > 0){
		timer1_count--;
		if(timer1_count <= 0){
			timer1Flag = 1;
		}
	}
	if(timer2_count > 0){
		timer2_count--;
		if(timer2_count <= 0){
			timer2Flag = 1;
		}
	}
	if(timer3_count > 0){
		timer3_count--;
		if(timer3_count <= 0){
			timer3Flag = 1;
		}
	}
	if(timer4_count > 0){
		timer4_count--;
		if(timer4_count <= 0){
			timer4Flag = 1;
		}
	}
}
