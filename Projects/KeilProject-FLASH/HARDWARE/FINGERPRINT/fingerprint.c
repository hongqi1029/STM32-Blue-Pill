#include "fingerprint.h"

/*
Ȩ�޹���
�����û�Ȩ�޷�Ϊ�������ͣ�
					�޸�ģ�����		��������û�		�޸������û�Ȩ��		��������
�����û���root		����				����				���޸�Ϊ����Ȩ��		����
��ͨ�û���normal	��ֹ				����(��root�û�)	��ֹ					����
��ʱ�û���temporary	��ֹ				��ֹ				��ֹ					(R/N�û�)ָ����N�λ����޴�

*/

uint8_t FPM_Test_Connection()
{
	uint8_t i;
	uint8_t array[26]={0x55,0xAA,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	USART3_CLEAR_QUEUE();
	USART3_WriteBytes(26, array);
	USART3_RECIEVE_BYTES(26);
	if(USART3_RECEIEVE_QUEUE_BUF[8]==0&&USART3_RECEIEVE_QUEUE_BUF[9]==0)
	{
		return 1;//���Գɹ�
	}
	else
	{
		return 0;//����ʧ��
	}
}