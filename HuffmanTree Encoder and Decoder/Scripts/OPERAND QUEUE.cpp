#include"operand.h"

int InitQueue(LinkQueue &Q)
//��ʼ������
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)
	{
		printf("�洢����ʧ��\n");
		exit(EXIT_FAILURE);
	}
	Q.front->next = NULL;
	Q.lengh = 0;	Q.flag = 1;
	return 1;
}

int EnLQueue(LinkQueue &Q, ElemType e)
//Ԫ��e�����
{
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)
	{
		printf("�洢����ʧ��\n");
		exit(EXIT_FAILURE);
	}
	p->data = e; p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	Q.lengh++;
	return 1;
}

int DeQueue(LinkQueue &Q, ElemType &e)
//�����У�ɾ����ͷԪ�أ�����e������ֵ
{
	if(Q.front == Q.rear)
	{
		printf("Error\n");
		return 0;
	}//�����п�,����Error
	QueuePtr p;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p)
		Q.rear = Q.front;//����������ֻ��һ��Ԫ�ؽ������Ҫͬʱ�޸Ķ�βָ��
	free(p);
	Q.lengh--;
	return 1;
}

void DestroyQueue(LinkQueue &Q)
//���ٶ���
{
	if(Q.front->next == NULL)
		return;
	while(Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	Q.lengh = 0;
	Q.flag = 0;
}

int GetHead(LinkQueue Q, ElemType &e)
//ȡ��ͷԪ�أ���������e��
{
	if(Empty(Q))
	{
		printf("����Ϊ��\n");
		return 0;
	}
	QueuePtr p;
	p = Q.front->next;
	e = p->data;
	return 1;
}

int Empty(LinkQueue Q)
//�ж϶����Ƿ�Ϊ��
// 1Ϊ��
// 0Ϊ�ǿ�
{
	if(Q.front==Q.rear)
		return 1;
	return 0;
}

int PrintQueue(LinkQueue Q)
//��������
{
	if(Empty(Q))
	{
		printf("�ö���Ϊ��\n");
		return 0;
	}
	else
	{
		QueuePtr p;
		p = Q.front->next;
		while(p)
		{
			printf("%c ",p->data);
			p = p->next;
		}
		printf("\n");
	}
	return 1;
}

int LenQueue(LinkQueue Q)
//���г���
{
	int i = 0;
	QueuePtr p;
	p = Q.front->next;
	if(Empty(Q))
		return 0;
	else
	{
		while(p)
		{
			i++;
			p = p->next;
		}
	}
	return i;
}                                                                                                                                                                                                                                   
