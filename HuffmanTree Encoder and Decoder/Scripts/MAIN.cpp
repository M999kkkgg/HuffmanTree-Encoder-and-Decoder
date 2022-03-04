#include"operand.h"

unsigned short int *CharArray;			//顺序存放字符数组
unsigned int *HFW;						//存放连续的有效权值
short int X;							//01码能否被7整除的标志

void END()
{
	system("cls");	//清屏
	NEWLINE;
	printf("          |--------------------------------------------|");	NEWLINE;
	printf("          |                                            |"); NEWLINE;
	printf("          |                 感谢使用                   |"); NEWLINE;
	printf("          |         Huffman encoder && decoder         |"); NEWLINE;
	printf("          |                                            |"); NEWLINE;
	printf("          |--------------------------------------------|");	NEWLINE;
	printf("          程序将于 3s 后退出	");
	for(int i = 3; i >=1; i--)
	{
		printf("%d",i);
		Sleep(second);
		printf("\b");
	}
	system("cls");	//清屏
	exit(EXIT_SUCCESS);
}

int main(void)
{
	Operate();
	END();
	return 0;
}