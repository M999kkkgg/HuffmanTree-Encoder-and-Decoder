#include"operand.h"

unsigned short int *CharArray;			//˳�����ַ�����
unsigned int *HFW;						//�����������ЧȨֵ
short int X;							//01���ܷ�7�����ı�־

void END()
{
	system("cls");	//����
	NEWLINE;
	printf("          |--------------------------------------------|");	NEWLINE;
	printf("          |                                            |"); NEWLINE;
	printf("          |                 ��лʹ��                   |"); NEWLINE;
	printf("          |         Huffman encoder && decoder         |"); NEWLINE;
	printf("          |                                            |"); NEWLINE;
	printf("          |--------------------------------------------|");	NEWLINE;
	printf("          ������ 3s ���˳�	");
	for(int i = 3; i >=1; i--)
	{
		printf("%d",i);
		Sleep(second);
		printf("\b");
	}
	system("cls");	//����
	exit(EXIT_SUCCESS);
}

int main(void)
{
	Operate();
	END();
	return 0;
}