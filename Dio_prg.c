/*
 * Dio_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo 1
 */

#include <avr/io.h>
#undef F_CPU
#define F_CPU 1000000
#include <util/delay.h>
#include "Std_types.h"
#include "Dio_int.h"
#include "Bit_math.h"


void Dio_vidSetPinDir(u8 Pin,u8 Dir)
{

u8 Port_Id;
u8 Pin_Loc;
Port_Id=Pin/8; //determine port number
Pin_Loc=Pin%8; //determine pin in the port

switch(Port_Id)
{

case 0://PORTA
	if(Dir==DIO_u8OUTPUT)
	{
		SET_BIT(DDRA,Pin_Loc);
	}
	else
	{
		CLR_BIT(DDRA,Pin_Loc);
	}
	break;
case 1://PORTB
	if(Dir==DIO_u8OUTPUT)
	{
		SET_BIT(DDRB,Pin_Loc);
	}
	else
	{
		CLR_BIT(DDRB,Pin_Loc);
	}
	break;
case 2://PORTC
	if(Dir==DIO_u8OUTPUT)
	{
		SET_BIT(DDRC,Pin_Loc);
	}

	else
	{
		CLR_BIT(DDRC,Pin_Loc);
	}
	break;
case 3://PORTD
	if(Dir==DIO_u8OUTPUT)
	{
		SET_BIT(DDRD,Pin_Loc);
	}
	else
	{
		CLR_BIT(DDRD,Pin_Loc);
	}
	break;
}

}


void Dio_vidSetPinVal(u8 Pin,u8 Val)
{


	u8 Port_Id;
	u8 Pin_Loc;
	Port_Id=Pin/8; //determine port number
	Pin_Loc=Pin%8; //determine pin in the port

	switch(Port_Id)
	{

	case 0://PORTA
		if(Val==DIO_u8HIGH)
		{
			SET_BIT(PORTA,Pin_Loc);
		}
		else
		{
			CLR_BIT(PORTA,Pin_Loc);
		}
		break;
	case 1://PORTB
		if(Val==DIO_u8HIGH)
		{
			SET_BIT(PORTB,Pin_Loc);
		}
		else
		{
			CLR_BIT(PORTB,Pin_Loc);
		}
		break;
	case 2://PORTC
		if(Val==DIO_u8HIGH)
		{
			SET_BIT(PORTC,Pin_Loc);
		}

		else
		{
			CLR_BIT(PORTC,Pin_Loc);
		}
		break;
	case 3://PORTD
		if(Val==DIO_u8HIGH)
		{
			SET_BIT(PORTD,Pin_Loc);
		}
		else
		{
			CLR_BIT(PORTD,Pin_Loc);
		}
		break;
	}

}


u8   Dio_vidGetPinVal(u8 Pin)
{

u8 Port_Id;
u8 Pin_Loc;
Port_Id=Pin/8; //determine port number
Pin_Loc=Pin%8; //determine pin in the port
switch(Port_Id)
{
case 0:
	return GET_BIT(PINA,Pin_Loc);
	break;

case 1:
	return GET_BIT(PINB,Pin_Loc);
	break;

case 2:
	return GET_BIT(PINC,Pin_Loc);
	break;

case 3:
	return GET_BIT(PIND,Pin_Loc);
	break;

}

return 0xFF;
}

