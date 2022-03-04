#include"huffmantree.h"
#include"file.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<math.h>

//作为Sleep函数参数
#define second 990

//用队列存储操作数
typedef char ElemType;
typedef struct QNode{
	ElemType	 data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;				//头指针
	QueuePtr rear;				//尾指针
	unsigned short int lengh;	//队列长度
	unsigned short int flag;	//初始化后flag=1, 否则flag=0 
}LinkQueue;

/*******   队列相关函数   ******/
int InitQueue(LinkQueue &Q);			//初始化队列
int EnLQueue(LinkQueue &Q,ElemType e);	//入队列
int DeQueue(LinkQueue &Q,ElemType &e);	//出队列
void DestroyQueue(LinkQueue &Q);			//销毁队列
int GetHead(LinkQueue Q,ElemType &e);	//取队头元素
int Empty(LinkQueue Q);					//判断队列是否为空
int PrintQueue(LinkQueue Q);			//遍历队列
int LenQueue(LinkQueue Q);				//队列长度

/******   操作及显示相关函数   ******/
int  Interface_A();							//第一显示界面
void Interface_B();							//第二显示界面
void Initialization(LinkQueue &Q, Text &T);	//初始化
int  Operand_correct(LinkQueue Q, Text T);	//操作数序列输入判断函数
void Operate();							    //主操作函数
void EmptyData(HuffmanTree &HT, HuffmanCode &HC, Text &T);
											//清空程序数据
void HFT_Code(HuffmanTree &HT, HuffmanCode &HC, Text &t);		
											//赫夫曼树封装函数
void PrintCode(HuffmanCode HC, Text t);		//打印并生成赫夫曼码表
void HFT_Decode(HuffmanTree HT, HuffmanCode HC, Text &t);//译码

/******   文件相关函数   ******/
void InitText(Text &T);		//初始化文本
void DestroyText(Text &T);	//销毁文本
void ReadText(Text &T);		//从txt文件逐个字符读入文本
void HUF();					//生成压缩文件
void GenerateText(Text T);	//译码后生成目标文件
void PrintText(Text T);		//打印文本标志域信息
void FileName(Text &T);		//输入文件名
void Read_File(Text &T);	//打开并读取文件

/******   赫夫曼构造函数   ******/
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, unsigned int *w, unsigned n);
//w存放n个字符的权值(w>0)，构造赫夫曼树HT，并求出n个字符的赫夫曼编码HC
void Select(HuffmanTree HT, unsigned y, unsigned &s1, unsigned &s2);
//在HT[1...n]选择parent为0且weight最小的两个结点，其序号为s1，s2 (s1<=s2)
