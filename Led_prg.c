/*
 * Led_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo 1
 */


#include <avr/io.h>
#include "../Lib/Std_types.h"
#include "../Lib/Bit_math.h"
#include "Dio_int.h"
#undef F_CPU             //to clear the warning of the redefinition of the cpu frequency
#define F_CPU 1000000    //this is a parameter in the util\delay library cpu frequency
#include <util/delay.h>
#include "Led_cfg.h"
#include "Led_int.h"


void Led_vidInit(u8 Led_Id)
{
switch(Led_Id)
{
case 1:
	Dio_vidSetPinDir(LED_u8ID_1,DIO_u8OUTPUT);
	break;

case 2:
	Dio_vidSetPinDir(LED_u8ID_2,DIO_u8OUTPUT);
	break;

case 3:
	Dio_vidSetPinDir(LED_u8ID_3,DIO_u8OUTPUT);
	break;

case 4:
	Dio_vidSetPinDir(LED_u8ID_4,DIO_u8OUTPUT);
	break;

case 5:
	Dio_vidSetPinDir(LED_u8ID_5,DIO_u8OUTPUT);
	break;

case 6:
	Dio_vidSetPinDir(LED_u8ID_6,DIO_u8OUTPUT);
	break;

case 7:
	Dio_vidSetPinDir(LED_u8ID_7,DIO_u8OUTPUT);
	break;

case 8:
	Dio_vidSetPinDir(LED_u8ID_8,DIO_u8OUTPUT);
	break;

}

}


void Led_vidTurnOn(u8 Led_Id)
{

	switch(Led_Id)
	{
	case 1:
		Dio_vidSetPinVal(LED_u8ID_1,DIO_u8HIGH);
		break;

	case 2:
		Dio_vidSetPinVal(LED_u8ID_2,DIO_u8HIGH);
		break;

	case 3:
		Dio_vidSetPinVal(LED_u8ID_3,DIO_u8HIGH);
		break;

	case 4:
		Dio_vidSetPinVal(LED_u8ID_4,DIO_u8HIGH);
		break;

	case 5:
		Dio_vidSetPinVal(LED_u8ID_5,DIO_u8HIGH);
		break;

	case 6:
		Dio_vidSetPinVal(LED_u8ID_6,DIO_u8HIGH);
		break;

	case 7:
		Dio_vidSetPinVal(LED_u8ID_7,DIO_u8HIGH);
		break;

	case 8:
		Dio_vidSetPinVal(LED_u8ID_8,DIO_u8HIGH);
		break;
	}

}


void Led_vidTurnOff(u8 Led_Id)
{

	switch(Led_Id)
	{
	case 1:
		Dio_vidSetPinVal(LED_u8ID_1,DIO_u8LOW);
		break;

	case 2:
		Dio_vidSetPinVal(LED_u8ID_2,DIO_u8LOW);
		break;

	case 3:
		Dio_vidSetPinVal(LED_u8ID_3,DIO_u8LOW);
		break;

	case 4:
		Dio_vidSetPinVal(LED_u8ID_4,DIO_u8LOW);
		break;

	case 5:
		Dio_vidSetPinVal(LED_u8ID_5,DIO_u8LOW);
		break;

	case 6:
		Dio_vidSetPinVal(LED_u8ID_6,DIO_u8LOW);
		break;

	case 7:
		Dio_vidSetPinVal(LED_u8ID_7,DIO_u8LOW);
		break;

	case 8:
		Dio_vidSetPinVal(LED_u8ID_8,DIO_u8LOW);
		break;
	}

}
