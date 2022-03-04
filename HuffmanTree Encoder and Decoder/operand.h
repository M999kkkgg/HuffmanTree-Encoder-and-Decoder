#include"huffmantree.h"
#include"file.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<math.h>

//��ΪSleep��������
#define second 990

//�ö��д洢������
typedef char ElemType;
typedef struct QNode{
	ElemType	 data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;				//ͷָ��
	QueuePtr rear;				//βָ��
	unsigned short int lengh;	//���г���
	unsigned short int flag;	//��ʼ����flag=1, ����flag=0 
}LinkQueue;

/*******   ������غ���   ******/
int InitQueue(LinkQueue &Q);			//��ʼ������
int EnLQueue(LinkQueue &Q,ElemType e);	//�����
int DeQueue(LinkQueue &Q,ElemType &e);	//������
void DestroyQueue(LinkQueue &Q);			//���ٶ���
int GetHead(LinkQueue Q,ElemType &e);	//ȡ��ͷԪ��
int Empty(LinkQueue Q);					//�ж϶����Ƿ�Ϊ��
int PrintQueue(LinkQueue Q);			//��������
int LenQueue(LinkQueue Q);				//���г���

/******   ��������ʾ��غ���   ******/
int  Interface_A();							//��һ��ʾ����
void Interface_B();							//�ڶ���ʾ����
void Initialization(LinkQueue &Q, Text &T);	//��ʼ��
int  Operand_correct(LinkQueue Q, Text T);	//���������������жϺ���
void Operate();							    //����������
void EmptyData(HuffmanTree &HT, HuffmanCode &HC, Text &T);
											//��ճ�������
void HFT_Code(HuffmanTree &HT, HuffmanCode &HC, Text &t);		
											//�շ�������װ����
void PrintCode(HuffmanCode HC, Text t);		//��ӡ�����ɺշ������
void HFT_Decode(HuffmanTree HT, HuffmanCode HC, Text &t);//����

/******   �ļ���غ���   ******/
void InitText(Text &T);		//��ʼ���ı�
void DestroyText(Text &T);	//�����ı�
void ReadText(Text &T);		//��txt�ļ�����ַ������ı�
void HUF();					//����ѹ���ļ�
void GenerateText(Text T);	//���������Ŀ���ļ�
void PrintText(Text T);		//��ӡ�ı���־����Ϣ
void FileName(Text &T);		//�����ļ���
void Read_File(Text &T);	//�򿪲���ȡ�ļ�

/******   �շ������캯��   ******/
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, unsigned int *w, unsigned n);
//w���n���ַ���Ȩֵ(w>0)������շ�����HT�������n���ַ��ĺշ�������HC
void Select(HuffmanTree HT, unsigned y, unsigned &s1, unsigned &s2);
//��HT[1...n]ѡ��parentΪ0��weight��С��������㣬�����Ϊs1��s2 (s1<=s2)
