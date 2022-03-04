#include"operand.h"
extern unsigned short int *CharArray;
extern unsigned int *HFW;

void InitText(Text &T)
//初始化文本
{
	T.character = (char *)malloc(MAX_N * sizeof(char));
	T.length = 0;
	T.ch_quantity = 0;
	T.mark = 0;
	T.flag = 1;
	T.filename[0] = '0';	T.filename[1] = '\0';
	T.letter_w = (unsigned int *)malloc((ASCII+1) * sizeof(unsigned int));	
	for(int i = 0; i <= ASCII; i++)
		T.letter_w[i] = 0;
}

void DestroyText(Text &T)
//销毁文本
{
	free(T.character);
	free(T.letter_w);
	free(CharArray);
	free(HFW);
	T.filename[0] = '\0';
	T.flag = 0;
	T.length = T.ch_quantity = T.mark = 0;
}

void PrintText(Text T)
//打印文本存储信息
{
	NEWLINE;
	printf("          文本域如下: ");	NEWLINE;
	SPACE;	printf("Filename:		");	printf("%s", T.filename);	NEWLINE;
	SPACE;	printf("Types_num:		");	printf("%d", T.ch_quantity);NEWLINE;
	SPACE;	printf("CharWeight([CHAR-ASCII]WEIGHT):");	NEWLINE;
	for(int i = 0, j = 0; i < ASCII; i++)
	{
		if(T.letter_w[i] > 0)
		{
			SPACE;	j++;
			if(i == (int)'\n')
				printf("[\\n-%3d]%4d   ",i, T.letter_w[i]);
			else if(i == (int)'\t')
				printf("[\\t-%3d]%4d   ",i, T.letter_w[i]);
			else
			{
				printf("[%2c-%3d]%4d   ", i, i, T.letter_w[i]);
			}
			if(j%3 == 0)
				NEWLINE;
		}
	}
	if(j == 0)
	{
		SPACE; printf("NULL");	NEWLINE;
	}
	if(j%3 != 0)
		NEWLINE;	
	SPACE;	printf("Length:		");		printf("%d", T.length);		NEWLINE;
	SPACE;	printf("Initialization:	");	printf("%d", T.flag);		NEWLINE;
	SPACE;	printf("Encode:		");		printf("%d", T.mark);		NEWLINE;
	NEWLINE;
}

void FileName(Text &T)
//输入文件名
{
	NEWLINE;
	SPACE;
	printf("Input your filename(xxx.txt): ");
	char ch;	int i=0;
	ch = getchar();
	while(ch != '\n')
	{
		T.filename[i] = ch;
		i++;
		ch = getchar();
	}
	T.filename[i] = '\0';
	flushall();
	NEWLINE;
}

void Read_File(Text &T)
{
	char ch;

	FileName(T);

	SPACE;	printf("The program is reading the FILE: (%s).", T.filename);	NEWLINE;
	FILE *fp = fopen(T.filename , "r"); 
	if(fp == NULL)
	{
		SPACE;
		printf("Failed to open the FILE: (T.filename).");	NEWLINE;
		T.filename[0] = '0';	T.filename[1] = '\0';
		NEWLINE;
		return ;
	}
	while((ch = getc(fp)) != EOF)
	{
		T.character[T.length] = ch;
		T.length++;
		if(T.letter_w[(int)ch] == 0)
			T.ch_quantity++;
		T.letter_w[(int)ch]++;
	}
	fclose(fp);
	SPACE;	printf("FILE: (%s) read completely. ", T.filename);	NEWLINE;
	NEWLINE;
}
