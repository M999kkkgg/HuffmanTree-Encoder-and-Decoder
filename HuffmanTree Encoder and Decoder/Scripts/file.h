#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ASCII 256
#define NEWLINE printf("\n")	/*����*/
#define LOOP while(1)			/*��ѭ��*/
#define SPACE printf("          ")	/*ʮ���ո�*/

//ASCII���256���ַ�ȡֵ
typedef struct{
	char filename[50];			//��¼�ļ���
	char *character;			//����txt�ı�����
	unsigned int  *letter_w;	//�����ַ���Ȩֵ�����ΪASCII
	int  ch_quantity;			//�����ַ��������
	int  length;				//�ı�����
	short int flag;				//��ʼ����flag=1, ����flag=0
	short int mark;				//δ����mark=0, �����mark=1
}Text;	




