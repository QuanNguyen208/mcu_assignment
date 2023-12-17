/*
 * read_button.c
 *
 *  Created on: Nov 7, 2023
 *      Author: Admin
 */


#include "button_reading.h"

static GPIO_PinState Reg3[num_of_buttons];
static GPIO_PinState Reg0[num_of_buttons];
static GPIO_PinState Reg1[num_of_buttons];
static GPIO_PinState Reg2[num_of_buttons];
/* Set time out */
int keyPressTime = 300;
/* Read input then set button flag */

void read_button() {
    for (int i = 0; i < num_of_buttons; i++) {
        Reg2[i] = Reg1[i];
        Reg1[i] = Reg0[i];

        if (i <= 1 || i >= 3) {
            Reg0[i] = HAL_GPIO_ReadPin(GPIOA, INPUT_BUTTON[i]);
        } else if (i == 2) {
            Reg0[i] = HAL_GPIO_ReadPin(GPIOB, INPUT_BUTTON[i]);
        }

        /* Check stable state */
        if (Reg0[i] == Reg1[i] && Reg1[i] == Reg2[i]) {
            if (Reg3[i] != Reg2[i]) {
                Reg3[i] = Reg2[i];
                if (Reg2[i] == PRESSED) {
                    /* Button is pressed set flag */
                    pressedButton_flag[i] = 1;
                    keyPressTime = 300;
                }
            } else {
                /* Long-press handle*/
                if (Reg2[i] == PRESSED) {
                    keyPressTime--;
                    if (keyPressTime == 0) {
                        pressedButton_flag[i] = 1;
                        keyPressTime = 100;
                    }
                }
            }
        }
    }
}


