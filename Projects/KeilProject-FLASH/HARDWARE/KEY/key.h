#ifndef __KEY_H
#define __KEY_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//������������
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/3
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////


//#define SW4 PEin(4)   	//PE4
//#define SW5 PEin(3)	//PE3
//#define KEY2 PEin(2)	//PE2
//#define WK_UP PAin(0)	//PA0  WK_UP

#define SW4  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)//��ȡ����4
#define SW5  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)//��ȡ����5



#define SW4_PRES 	1	//SW4����
#define SW5_PRES	2	//SW5����


void KEY_Init(void);//IO��ʼ��
u8 KEY_Scan(u8);  	//����ɨ�躯��
#endif
