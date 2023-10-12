/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: lenovo 1
 */

#undef F_CPU
#define F_CPU 1000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Std_types.h"
#include "Bit_math.h"
#include "Dio_int.h"
#include "Led_int.h"

u32 Ovf_Count;
void Timer_vidInit(void);
void Scheduler(void);

typedef struct{

u32 First_Delay;
u32 Periodicity;
void (* Pf_Task_Code)(void);

}Task_Type;


/*array of pointer to structure*/
Task_Type* Task_Array[2];

void App1_Fun(void);
void App2_Fun(void);


int main(void)
{

	Task_Type App1;
	Task_Type App2;

	App1.First_Delay=0;
	App1.Periodicity=100;
	App1.Pf_Task_Code=App1_Fun;

	App2.First_Delay=100;
	App2.Periodicity=200;
	App2.Pf_Task_Code=App2_Fun;

	Task_Array[0]=&App1;
	Task_Array[1]=&App2;

	Led_vidInit(LED_1);
	Led_vidInit(LED_2);

	Timer_vidInit();
while(1)
{

}


return 0;
}




void Timer_vidInit(void)
{

TCNT0 = 192;
Ovf_Count=0;
/*NORMAL MODE NP ORESCALLER 8MHZ FREQ*/
TCCR0=0;
SET_BIT(TCCR0,0);

SET_BIT(TIMSK,0);
SET_BIT(SREG,7);
}



ISR(TIMER0_OVF_vect)
{

	Ovf_Count++;
	if(Ovf_Count==32)
	{
		Ovf_Count=0;
		TCNT0=192;
		/*THIS LINE WILL BE EXECUTED EACH 1 MSEC*/
		Scheduler();

	}
}



void App1_Fun(void)
{
static u8 Flag=0;
if(Flag==0)
{
	Led_vidTurnOn(LED_1);
	Flag=1;
}
else
{
Led_vidTurnOff(LED_1);
Flag=0;
}

}

void App2_Fun(void)
{
	static u8 Flag=0;
	if(Flag==0)
	{
		Led_vidTurnOn(LED_2);
		Flag=1;
	}
	else
	{
	Led_vidTurnOff(LED_2);
	Flag=0;
	}
}

void Scheduler(void)
{

u8 Task_Counter;

for (Task_Counter = 0; Task_Counter < 2; ++Task_Counter)
{

	if (Task_Array[Task_Counter]->First_Delay == 0)
	{

        /*call the function(pointer to function) in
        *  the structure using the pointer to structure*/

	   Task_Array[Task_Counter]->Pf_Task_Code();
	   Task_Array[Task_Counter]->First_Delay=Task_Array[Task_Counter]->Periodicity - 1;

	}
	else
	{

		Task_Array[Task_Counter]->First_Delay--;
	}

}

}



