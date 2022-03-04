#include"operand.h"

int InitQueue(LinkQueue &Q)
//初始化队列
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)
	{
		printf("存储分配失败\n");
		exit(EXIT_FAILURE);
	}
	Q.front->next = NULL;
	Q.lengh = 0;	Q.flag = 1;
	return 1;
}

int EnLQueue(LinkQueue &Q, ElemType e)
//元素e入队列
{
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)
	{
		printf("存储分配失败\n");
		exit(EXIT_FAILURE);
	}
	p->data = e; p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	Q.lengh++;
	return 1;
}

int DeQueue(LinkQueue &Q, ElemType &e)
//出队列，删除队头元素，并用e返回其值
{
	if(Q.front == Q.rear)
	{
		printf("Error\n");
		return 0;
	}//若队列空,返回Error
	QueuePtr p;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p)
		Q.rear = Q.front;//对于链队列只有一个元素结点的情况要同时修改队尾指针
	free(p);
	Q.lengh--;
	return 1;
}

void DestroyQueue(LinkQueue &Q)
//销毁队列
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
//取队头元素，并储存在e中
{
	if(Empty(Q))
	{
		printf("队列为空\n");
		return 0;
	}
	QueuePtr p;
	p = Q.front->next;
	e = p->data;
	return 1;
}

int Empty(LinkQueue Q)
//判断队列是否为空
// 1为空
// 0为非空
{
	if(Q.front==Q.rear)
		return 1;
	return 0;
}

int PrintQueue(LinkQueue Q)
//遍历队列
{
	if(Empty(Q))
	{
		printf("该队列为空\n");
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
//队列长度
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
