#ifndef _OLED_H
#define _OLED_H

#include "sys.h"

#define OLED_ADDRESS	0x78 //ͨ������0R����,������0x78��0x7A������ַ -- Ĭ��0x78
extern char OLED_STR_BUF[100];
extern void OLED_Write_Reg(uint8_t regAddr, uint8_t regData);
extern void OLED_WriteCmd(unsigned char I2C_Command);
extern void OLED_WriteDat(unsigned char I2C_Data);//д����
extern void OLED_Init(void);
extern void OLED_SetPos(unsigned char x, unsigned char y); //������ʼ������
extern void OLED_Fill(unsigned char fill_Data);//ȫ�����
extern void OLED_CLS(void);//����
extern void OLED_ON(void);
extern void OLED_OFF(void);
extern void OLED_ShowStr(unsigned char x, unsigned char y, char ch[], unsigned char TextSize);
extern void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N);
extern void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);





#endif
