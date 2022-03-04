#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ASCII 256
#define NEWLINE printf("\n")	/*换行*/
#define LOOP while(1)			/*死循环*/
#define SPACE printf("          ")	/*十个空格*/

//ASCII码表256个字符取值
typedef struct{
	char filename[50];			//记录文件名
	char *character;			//复制txt文本内容
	unsigned int  *letter_w;	//各种字符的权值，标号为ASCII
	int  ch_quantity;			//出现字符种类个数
	int  length;				//文本长度
	short int flag;				//初始化后flag=1, 否则flag=0
	short int mark;				//未编译mark=0, 编译后mark=1
}Text;	




