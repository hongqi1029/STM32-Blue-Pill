#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"

void All_Init()
{
	delay_init();	    //��ʱ������ʼ��	
	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
}
int main(void)
 {	
	All_Init();
	while(1)
	{
		LED=~LED;
		delay_ms(500);	//��ʱ300ms
	}
 }


