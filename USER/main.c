#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
#include "sys.h"
#include "led.h"
#include "tim.h"
#include "bee.h"
#include "oled.h"
#include "tim.h"
extern volatile unsigned char PSC_Init[];
extern volatile unsigned char NOTE_SY[];
extern volatile unsigned int sec;
extern volatile unsigned int min;
extern volatile unsigned int hour;
void aatimer(void)
	{
		OLED_Init();		//OLED初始化
	    TIM3_Init(8400,10000);	//定时中断初始化
		while(1)
		{
			if(hour>=24)
		{
			hour=0;
		}
		if(min>=60)
		{
			min=0;
			hour++;
			OLED_ShowNum(1, 2, min,2);
		}	
	  if(sec>=60)
		{
			sec=0;
			min++;
			OLED_ShowNum(1, 5, min,2);	
		}
		OLED_ShowNum(1, 8, sec, 2);			
	 }	
	}		
 
int main(void)
{

  while(1)
	  {
		  aatimer();
       }
 }
