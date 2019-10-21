#ifndef _stm32_flash_H
#define _stm32_flash_H

#include "sys.h"


//�û������Լ�����Ҫ����
#define STM32_FLASH_SIZE 64 	 //��ѡSTM32��FLASH������С(��λΪK)

//FLASH��ʼ��ַ
#define STM32_FLASH_BASE 0x08000000 	//STM32 FLASH����ʼ��ַ
#define STM32_FLASH_SAVE_ADDR  0X0800F000		
//����FLASH �����ַ(����Ϊż��������ֵҪ���ڱ�������ռ��FLASH�Ĵ�С+0X08000000)

vu16 STM32_FLASH_ReadHalfWord(u32 faddr); 
void STM32_FLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite);		//��ָ����ַ��ʼд��ָ�����ȵ�����
void STM32_FLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead);   		//��ָ����ַ��ʼ����ָ�����ȵ�����
					   


#endif

/*
const u8 text_buf[]="www.prechin.net";
#define TEXTLEN sizeof(text_buf)
u8 read_buf[TEXTLEN];

        STM32_FLASH_Write(STM32_FLASH_SAVE_ADDR,(u16*)text_buf,TEXTLEN);
        printf("write : %s\r\n",text_buf);

        delay_ms(100);
        STM32_FLASH_Read(STM32_FLASH_SAVE_ADDR,(u16 *)read_buf,TEXTLEN);
        printf("read  : %s\r\n",read_buf);
        delay_ms(100);
*/



