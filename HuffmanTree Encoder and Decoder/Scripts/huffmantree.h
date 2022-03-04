#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//最大字符数
#define MAX_N 50000

//动态分配数组存储赫夫曼树
typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;

//动态分配存储赫夫曼编码表
typedef char **HuffmanCode;		//顺序存放对应编码
