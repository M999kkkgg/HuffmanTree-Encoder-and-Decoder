#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//����ַ���
#define MAX_N 50000

//��̬��������洢�շ�����
typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;

//��̬����洢�շ��������
typedef char **HuffmanCode;		//˳���Ŷ�Ӧ����
