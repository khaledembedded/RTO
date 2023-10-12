/*
 * Led_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo 1
 */

#ifndef LED_INT_H_
#define LED_INT_H_

#define LED_1  1
#define LED_2  2
#define LED_3  3
#define LED_4  4
#define LED_5  5
#define LED_6  6
#define LED_7  7
#define LED_8  8

void Led_vidInit(u8 Led_Id);
void Led_vidTurnOn(u8 Led_Id);
void Led_vidTurnOff(u8 Led_Id);



#endif /* LED_INT_H_ */
