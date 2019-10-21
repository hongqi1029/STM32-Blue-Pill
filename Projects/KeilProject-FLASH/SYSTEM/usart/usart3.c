/**
  ***************************************************************
  * @file    usart3.c
  * @author  Siyou luo
  * @contact siyouluo11@gmail.com
  * @version V1.0
  * @date    10-Sept-2019
  * @brief   USART3 ����3��������,����3���ں�ָ��ģ��ͨ��
  ******************************************************************************
  * @resources
  * USART3
  * 	TX (GPIOB_Pin_10)
  *		RX (GPIOB_Pin_11)
  ******************************************************************************
  */
#include "usart3.h"
#include "usart1.h"
uint8_t USART3_RECEIEVE_QUEUE_BUF[USART3_MAX_QUEUE_BUF_SIZE];//USART3���ڻ�����
uint8_t USART3_QUEUE_PTR=0;//���ڻ���������β�����λ��

//int fputc(int ch, FILE *p)
//{
//	USART_SendData(USART3,(u8)ch);
//	while(USART_GetFlagStatus(USART3,USART_FLAG_TC) != SET);
//	return ch;
//}


/**
  * @brief :�ж�USART3���ڻ������Ƿ���
  * @param :void
  * @retval :����1:�� ����0:����
  * @usage:if(USART3_QUEUE_FULL()==1)...	if(USART3_QUEUE_FULL()==0)...
  */
uint8_t  USART3_QUEUE_FULL(void)
{
    return (uint8_t)(USART3_QUEUE_PTR==USART3_MAX_QUEUE_BUF_SIZE);
}


/**
  * @brief	:�ж�USART3���ڻ������Ƿ��
  * @param	:void
  * @retval	:����1:�� ����0:�ǿ�
  * @usage	:if(USART3_QUEUE_EMPTY()==1)...	if(USART3_QUEUE_EMPTY()==0)...
  */
uint8_t USART3_QUEUE_EMPTY(void)
{
    return (uint8_t)(USART3_QUEUE_PTR==0);
}

/**
  * @brief	:��USART3���ڻ������ڴ���һ���ֽ�����
  * @param	ch: uint8_t���ͣ�д��ch
  * @retval	:1,��������д��ʧ�ܣ�0��д��ɹ�
  * @usage	:USART3_PUSH_QUEUE(0x3f)
  */
uint8_t USART3_PUSH_QUEUE(uint8_t ch)
{
    if(USART3_QUEUE_FULL())
    {
        printf("err: queue full!\n");
        return 1;
    }
    USART3_RECEIEVE_QUEUE_BUF[USART3_QUEUE_PTR]=ch;
    USART3_QUEUE_PTR++;
	return 0;
}
/**
  * @brief	:��մ��ڻ�����
  * @param	:void
  * @retval	:void
  * @usage	:
  */
void USART3_CLEAR_QUEUE()
{
	USART3_QUEUE_PTR=0;
}

/**
  * @brief	:��ȡ���ڻ���������Ч�ֽ���
  * @param	:void
  * @retval	:uint8_t
  * @usage	:
  */
uint8_t USART3_GET_NUM_QUEUE()
{
	return USART3_QUEUE_PTR;
}
/**
  * @brief	:�ȴ�USART3���յ�n���ֽ�
  * @param	:uint8_t n
  * @retval	:0
  * @usage	:
  */
uint8_t USART3_RECIEVE_BYTES(uint8_t n)
{
	while(USART3_GET_NUM_QUEUE()<n);
	return 0;
}



/**
  * @brief	:����USART3дһ���ֽ�����
  * @param	ch: uint8_t ���ͣ���TX�ܽ�д��
  * @retval	:void
  * @usage	:USART3_WriteByte(0x3f)
  */
void USART3_WriteByte(uint8_t ch)
{
    USART_SendData(USART3,(u8)ch);
    while(USART_GetFlagStatus(USART3,USART_FLAG_TC) != SET);
}
/**
  * @brief	:����USART3дn�������洢���ֽ�����
  * @param	n: uint8_t���ͣ�д�����ֽڸ���
  * @param	*p: uint8_t���ͣ���д�����ֽ������׵�ַ
  * @retval	:void
  * @usage	:uint8_t temp_array[n]={0x01,0x02,0x03,...};
  * @usage	:USART3_WriteBytes(n, temp_array);
  */
void USART3_WriteBytes(uint8_t n, uint8_t *p)
{
    uint8_t i;
    for(i=0; i<n; i++)
    {
        USART3_WriteByte(p[i]);
    }
}

void USART3_Init(u32 baud)
{
    //GPIO�˿�����
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);


    /*  ����GPIO��ģʽ��IO�� */
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;//TX			   //�������PB10
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;	    //�����������
    GPIO_Init(GPIOB,&GPIO_InitStructure);  /* ��ʼ����������IO */
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;//RX			 //��������PB11
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;		  //ģ������
    GPIO_Init(GPIOB,&GPIO_InitStructure); /* ��ʼ��GPIO */


    //USART3 ��ʼ������
    USART_InitStructure.USART_BaudRate = baud;//����������
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
    USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
    USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
    USART_Init(USART3, &USART_InitStructure); //��ʼ������3

    USART_Cmd(USART3, ENABLE);  //ʹ�ܴ���3

    USART_ClearFlag(USART3, USART_FLAG_TC);

    USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//��������ж�

    //Usart3 NVIC ����
    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;//����3�ж�ͨ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;//��ռ���ȼ�3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;		//�����ȼ�2
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��

    NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ�����


}

/*******************************************************************************
* �� �� ��         : USART3_IRQHandler
* ��������		   : USART3�жϺ���
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void USART3_IRQHandler(void)                	//����1�жϷ������
{
    if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)  //�����ж�
    {
		USART3_PUSH_QUEUE(USART_ReceiveData(USART3));
    }
    USART_ClearFlag(USART3,USART_FLAG_TC);
}
