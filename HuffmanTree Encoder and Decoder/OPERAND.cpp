#include"operand.h"
extern unsigned short int *CharArray;
extern unsigned int *HFW;

int  Interface_A()
{
	char n;
	NEWLINE;
	printf("          |--------------------------------------------|");	NEWLINE;
	printf("          |                                            |");	NEWLINE;
	printf("          |              �շ��� ��/�� ����             |");	NEWLINE;
	printf("          |               ����: 19218101               |");	NEWLINE;
	printf("          |           Huffman encoder / decoder        |");	NEWLINE;
	printf("          |             Designer: 19218101             |");	NEWLINE;
	printf("          |                                            |");	NEWLINE;
	printf("          |--------------------------------------------|");	NEWLINE;
	printf("          |                                            |");	NEWLINE;
	printf("          |--------------------------------------------|");	NEWLINE;
	printf("          |                                            |");	NEWLINE;
	printf("          |                  ʹ��˵��                  |");	NEWLINE;
	printf("          |      ������ɶ�һ���ı��ļ��е��ַ���      |");	NEWLINE;
	printf("          |      �кշ������벢�����ɱ����ļ���Ҳ      |");	NEWLINE;
	printf("          |      �ɽ������ļ����뻹ԭΪ�ı��ļ���      |");	NEWLINE;
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
	printf("          ����Ķ����Ƿ������һ��������(Y/N)��");
	LOOP
	{
		n = getchar();
		if(n == 'Y' || n == 'y')
		{
			system("cls");	//����
			return 1;
		}
		else if(n == 'N' || n== 'n')
			return 0;
		else
		{
			printf("          �����ʽ��������������");	NEWLINE;
			printf("          ����Ķ����Ƿ������һ��������(Y/N): ");
			flushall();		//��ջ�����
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
	printf("          |                  ��λ˵��                  |");	NEWLINE;
	printf("          |      1.��ӡ�ı��洢��Ϣ                    |");	NEWLINE;
	printf("          |      2.�򿪲���ȡ�ļ�                      |");	NEWLINE;
	printf("          |      3.�շ������벢����ѹ���ļ�            |");	NEWLINE;
	printf("          |      4.��ӡ����洢��code.txt��          |");	NEWLINE;
	printf("          |      5.�Ա�������ɵ��ļ����벢����txt�ļ� |");	NEWLINE;
	printf("          |      6.�����ʼ��                          |");	NEWLINE;
	printf("          |      7.�������                            |");	NEWLINE;
	printf("          |      8.�˳�����                            |");	NEWLINE;
	printf("          |                                            |");	NEWLINE;
	printf("          |--------------------------------------------|");	NEWLINE;
	printf("          ������������������, ������ɺ� �س� ��������");	NEWLINE;
	printf("          ����: ���� [72314568�س�] ���� [8�س�]");		NEWLINE;
	printf("          �������������(1 - 8): ");
	flushall();			//��ջ�����
}

void Initialization(LinkQueue &Q, Text &T)
{
	NEWLINE;
	SPACE;	printf("Initializing");	NEWLINE;
	InitQueue(Q);			//���������г�ʼ��
	InitText(T);			//�ı��ṹ���ʼ��
	SPACE;	printf("Completely");	NEWLINE;
	NEWLINE;
}

void EmptyData(HuffmanTree &HT, HuffmanCode &HC, Text &T)
//����ı�����
{
	NEWLINE;
	SPACE;	printf("Destorying");	NEWLINE;
	DestroyText(T);
	SPACE;	printf("Completely");	NEWLINE;
	NEWLINE;
}

void Operate()
{
	LinkQueue operand;			//�������������operand
	ElemType in,out;			//��¼�������е�ֵ, ��θ���
	Text t;						//����洢�ı��ṹ��
	HuffmanTree HFTree;			//����շ�����
	HuffmanCode HFCode;			//����շ�������
	
	t.flag = 0;	operand.flag = 0;
								//����δ��ʼ��
	/***��һ��ʾ����***/
	if(!Interface_A())
		return;
	/***�ڶ���ʾ����***/
	Interface_B();
	/***��ʼ��***/
	InitQueue(operand);			//���������г�ʼ��
	InitText(t);			//�ı��ṹ���ʼ��

	/***��ѭ��***/
	LOOP
	{
		/***������***/
		in = getchar();
		while(in != '\n')
		{
			EnLQueue(operand, in);
			in = getchar();
		}
		flushall();				//��ջ�����
		printf("          ������Ĳ���������: ");
		PrintQueue(operand);

		/***������***/
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
					SPACE;	printf("������1 - 8����������");	NEWLINE;
				}
			}
		}
		flushall();
		DestroyQueue(operand);	InitQueue(operand);
		printf("          ����������������(1 - 8): ");
	}
}
