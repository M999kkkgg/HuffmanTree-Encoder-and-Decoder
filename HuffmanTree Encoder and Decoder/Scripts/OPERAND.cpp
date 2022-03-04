#include"operand.h"
extern unsigned short int *CharArray;
extern unsigned int *HFW;

int  Interface_A()
{
	char n;
	NEWLINE;
	printf("          |--------------------------------------------|");	NEWLINE;
	printf("          |                                            |");	NEWLINE;
	printf("          |              赫夫曼 编/译 码器             |");	NEWLINE;
	printf("          |               作者: 19218101               |");	NEWLINE;
	printf("          |           Huffman encoder / decoder        |");	NEWLINE;
	printf("          |             Designer: 19218101             |");	NEWLINE;
	printf("          |                                            |");	NEWLINE;
	printf("          |--------------------------------------------|");	NEWLINE;
	printf("          |                                            |");	NEWLINE;
	printf("          |--------------------------------------------|");	NEWLINE;
	printf("          |                                            |");	NEWLINE;
	printf("          |                  使用说明                  |");	NEWLINE;
	printf("          |      本程序可对一个文本文件中的字符进      |");	NEWLINE;
	printf("          |      行赫夫曼编码并且生成编码文件。也      |");	NEWLINE;
	printf("          |      可将编码文件译码还原为文本文件。      |");	NEWLINE;
	printf("          |              Direction for use             |");	NEWLINE;
	printf("          |      Huffman encoding a file(.txt) to      |");	NEWLINE;
	printf("          |      generate a file(Encoded txt.huf).     |");	NEWLINE;
	printf("          |      And alse decode it and restore it     |");	NEWLINE;
	printf("          |      to a file(Decoded.txt).               |");	NEWLINE;
	printf("          |                                            |");	NEWLINE;
	printf("          |--------------------------------------------|");	NEWLINE;
	printf("          |                                            |");	NEWLINE;
	printf("          |--------------------------------------------|");	NEWLINE;
	printf("          |                                            |"); NEWLINE;
	printf("          |    Huffman encoder && decoder by 19218101  |"); NEWLINE;
	printf("          |     Compiled on %s at %s    |", __DATE__, __TIME__); NEWLINE;
	printf("          |                                            |");	NEWLINE;
	printf("          |--------------------------------------------|");	NEWLINE;
	printf("          完成阅读，是否进入下一步操作？(Y/N)：");
	LOOP
	{
		n = getchar();
		if(n == 'Y' || n == 'y')
		{
			system("cls");	//清屏
			return 1;
		}
		else if(n == 'N' || n== 'n')
			return 0;
		else
		{
			printf("          输入格式错误，请重新输入");	NEWLINE;
			printf("          完成阅读，是否进入下一步操作？(Y/N): ");
			flushall();		//清空缓冲区
		}
	}
}

void Interface_B()
{
	NEWLINE;
	printf("          |--------------------------------------------|");	NEWLINE;
	printf("          |                                            |");	NEWLINE;
	printf("          |           Huffman encoder / decoder        |");	NEWLINE;
	printf("          |                                            |");	NEWLINE;
	printf("          |--------------------------------------------|");	NEWLINE;
	printf("          |                                            |");	NEWLINE;
	printf("          |                  键位说明                  |");	NEWLINE;
	printf("          |      1.打印文本存储信息                    |");	NEWLINE;
	printf("          |      2.打开并读取文件                      |");	NEWLINE;
	printf("          |      3.赫夫曼编码并生成压缩文件            |");	NEWLINE;
	printf("          |      4.打印码表并存储在code.txt中          |");	NEWLINE;
	printf("          |      5.对编码后生成的文件译码并生成txt文件 |");	NEWLINE;
	printf("          |      6.程序初始化                          |");	NEWLINE;
	printf("          |      7.清空数据                            |");	NEWLINE;
	printf("          |      8.退出程序                            |");	NEWLINE;
	printf("          |                                            |");	NEWLINE;
	printf("          |--------------------------------------------|");	NEWLINE;
	printf("          操作数可以连续输入, 输入完成后按 回车 结束输入");	NEWLINE;
	printf("          例如: 输入 [72314568回车] 或者 [8回车]");		NEWLINE;
	printf("          输入操作数序列(1 - 8): ");
	flushall();			//清空缓冲区
}

void Initialization(LinkQueue &Q, Text &T)
{
	NEWLINE;
	SPACE;	printf("Initializing");	NEWLINE;
	InitQueue(Q);			//操作数队列初始化
	InitText(T);			//文本结构体初始化
	SPACE;	printf("Completely");	NEWLINE;
	NEWLINE;
}

void EmptyData(HuffmanTree &HT, HuffmanCode &HC, Text &T)
//清空文本数据
{
	NEWLINE;
	SPACE;	printf("Destorying");	NEWLINE;
	DestroyText(T);
	SPACE;	printf("Completely");	NEWLINE;
	NEWLINE;
}

void Operate()
{
	LinkQueue operand;			//定义操作数队列operand
	ElemType in,out;			//记录进出队列的值, 逐次更新
	Text t;						//定义存储文本结构体
	HuffmanTree HFTree;			//定义赫夫曼树
	HuffmanCode HFCode;			//定义赫夫曼编码
	
	t.flag = 0;	operand.flag = 0;
								//标明未初始化
	/***第一显示界面***/
	if(!Interface_A())
		return;
	/***第二显示界面***/
	Interface_B();
	/***初始化***/
	InitQueue(operand);			//操作数队列初始化
	InitText(t);			//文本结构体初始化

	/***死循环***/
	LOOP
	{
		/***进队列***/
		in = getchar();
		while(in != '\n')
		{
			EnLQueue(operand, in);
			in = getchar();
		}
		flushall();				//清空缓冲区
		printf("          你输入的操作数序列: ");
		PrintQueue(operand);

		/***出队列***/
		while(operand.lengh > 0)
		{
			DeQueue(operand, out);
			switch(out)
			{
			case '1': PrintText(t);	break;
			case '2': Read_File(t);	break;
			case '3': HFT_Code(HFTree, HFCode, t);	break;
			case '4': PrintCode(HFCode, t);			break;
			case '5': HFT_Decode(HFTree, HFCode, t);break;
			case '6': Initialization(operand, t);	break;
			case '7': EmptyData(HFTree, HFCode, t);  break;
			case '8': return;
			default : 
				{
					DestroyQueue(operand);
					InitQueue(operand);
					SPACE;	printf("请输入1 - 8的数字序列");	NEWLINE;
				}
			}
		}
		flushall();
		DestroyQueue(operand);	InitQueue(operand);
		printf("          请继续输入操作序列(1 - 8): ");
	}
}
