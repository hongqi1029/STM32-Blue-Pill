#ifndef _FINGERPRINT_H
#define _FINGERPRINT_H

#include "sys.h"
#include "usart3.h"

//�����ʶ����
// 		Packet���					Code�����ʶ����
#define COMMAND_PACKET_PREFIX		0xAA55				//�����
#define RESPONSE_PACKET_PREFIX		0x55AA				//��Ӧ��
#define COMMAND_DATA_PACKET_PREFIX	0xA55A				//ָ�����ݰ�
#define RESPONSE_DATA_PACKET_PREFIX 0x5AA5				//��Ӧ���ݰ�


//ͨѶ��������
// ��������(Command Name)			������(Code)	�����(Function)
#define CMD_TEST_CONNECTION 		0x0001			//�������豸��ͨѶ����
#define CMD_SET_PARAM 				0x0002			//�����豸����(Device ID, Security Level, Baudrate, Duplication Check, Auto Learn, Timeout)
#define CMD_GET_PARAM 				0x0003			//��ȡ�豸����(Device ID, Security Level, Baudrate, Duplication Check, Auto Learn, Timeout)
#define CMD_GET_DEVICE_INFO 		0x0004			//��ȡ�豸��Ϣ
#define CMD_ENTER_IAP_MODE			0x0005			//���豸����ΪIAP״̬
#define CMD_GET_IMAGE				0x0020			//�Ӳɼ����ɼ�ָ��ͼ�񲢱�����ImageBuffer��
#define CMD_FINGER_DETECT			0x0021			//���ָ������״̬
#define CMD_UP_IMAGE				0x0022			//��������ImageBuffer�е�ָ��ͼ���ϴ���HOST
#define CMD_DOWN_IMAGE				0x0023			//HOST����ָ��ͼ��ģ���ImageBuffer��
#define CMD_SLED_CTRL				0x0024			//���Ʋɼ�������ƵĿ�/��(ע:�뵼�崫�������ô˹���)
#define CMD_STORE_CHAR				0x0040			//��ָ�����Ram Buffer�е�Templateע�ᵽָ����ŵĿ���
#define CMD_LOAD_CHAR				0x0041			//��ȡ����ָ������е�Template��ָ����ŵ�Ram Buffer
#define CMD_UP_CHAR					0x0042			//��������ָ����ŵ�Ram Buffer�е�Template�ϴ���HOST
#define CMD_DOWN_CHAR				0x0043			//��HOST����Template��ģ��ָ����ŵ�Ram Buffer��
#define CMD_DEL_CHAR				0x0044			//ɾ��ָ����ŷ�Χ�ڵ�Template
#define CMD_GET_EMPTY_ID			0x0045			//��ȡָ����Χ�ڿ�ע���(û��ע���)��һ��ģ����
#define CMD_GET_STATUS				0x0046			//��ȡָ����ŵ�ģ��ע��״̬
#define CMD_GET_BROKEN_ID			0x0047			//���ָ����ŷ�Χ�ڵ�����ָ��ģ���Ƿ���ڻ�������
#define CMD_GET_ENROLL_COUNT		0x0048			//��ȡָ����ŷ�Χ����ע���ģ�����
#define CMD_GENERATE				0x0060			//��ImageBuffer�е�ָ��ͼ������ģ�����ݣ���������ָ����ŵ�Ram Buffer��
#define CMD_MERGE					0x0061			//��������Ram Buffer�е���������ģ�������ںϳ�һ��ģ������
#define CMD_MATCH					0x0062			//ָ��Ram Buffer�е�����ָ��ģ��֮�����1:1�ȶ�
#define CMD_SEARCH					0x0063			//ָ��Ram Buffer�е�ģ����ָ�ƿ���ָ����ŷ�Χ�ڵ�����ģ��֮�����1:N�ȶ�
#define CMD_VERIFY					0x0064			//ָ��Ram Buffer�е�ָ��ģ����ָ�ƿ���ָ����ŵ�ָ��ģ��֮�����1:1�ȶ�
#define CMD_SET_MODULE_SN			0x0008			//���豸������ģ�����к���Ϣ(Module SN)
#define CMD_GET_MODULE_SN			0x0009			//��ȡ���豸��ģ�����к�(Module SN)
#define CMD_FP_CANCEL				0x0025			//ȡ��ָ�Ʋɼ�����(ֻ�����ڴ�TimeOut�����Ļ���������)
#define CMD_GET_ENROLLED_ID_LIST	0x0049			//��ȡ��ע��User ID�б�
#define CMD_ENTER_STANDY_STATE		0x000C			//ʹģ���������״̬(��Щģ�鲻֧�����߹��ܣ���Ȼģ����Ӧָ��سɹ�)


















#endif
