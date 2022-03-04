#include"operand.h"
extern unsigned short int *CharArray;
extern unsigned int *HFW;
extern short int X;

//封装函数
void HFT_Code(HuffmanTree &HT, HuffmanCode &HC, Text &t)
{
	if(t.filename[0] == '0')
	{
		SPACE;	printf("Error: NO FILE\n");
		return;
	}

	unsigned short int i, j;

	HFW = (unsigned int *)malloc(t.ch_quantity * sizeof(unsigned int));
	CharArray = (unsigned short int *)malloc((t.ch_quantity+1) * sizeof(unsigned short int));	
	CharArray[t.ch_quantity]='\0';
	for(i = 0, j = 0; j < ASCII; j++)
	{
		if(t.letter_w[j] > 0)
		{
			HFW[i] = t.letter_w[j];
			CharArray[i] = (unsigned short int)j;
			i++;
		}
	}//将t.letter_w中的有效权值(大于0)复制到w中, 使有效权值连续
	 //存储t.letter_w中表示的有效字符(权值大于0)
	HuffmanCoding(HT, HC, HFW, t.ch_quantity);
	t.mark = 1;

	//生成01码文件
	FILE *in_fp = fopen(t.filename, "r");
	FILE *out_fp = fopen("Encoded.txt", "wb");
	char ch;
	int x;
	while((ch = getc(in_fp)) != EOF)
	{
		for(x = 0; x < t.ch_quantity; x++)
		{
			if(ch == CharArray[x])
			{
				fputs(HC[x+1], out_fp);
				break;
			}
			else
				continue;
		}
	}

	fclose(in_fp);
	fclose(out_fp);

	//将X位01码转换为一个char存储在压缩文件中
	FILE *fp = fopen("Encoded.txt", "r");
	FILE *hp = fopen("EncodedText.huf", "wb");

	int Hflag = 64;
	int num =0;
	char chput = 0;
	
	ch = getc(fp);
	while(!feof(fp))
	{
		num++;
		chput += Hflag * (ch - '0');
		Hflag /= 2;
		X = 0;
		if(num % 7 == 0)
		{
			fputc(chput, hp);
			chput = 0;
			Hflag = 64;
			X = 1;
		}
		ch = getc(fp);
		if(X == 0 && ch == EOF)
		{
			fputc(chput, hp);
			break;
		}
	}

	fclose(fp);
	fclose(hp);
	
	NEWLINE;
	SPACE;	printf("%s has been encoded.", t.filename);	NEWLINE;	
	SPACE;	printf("Encoded filename_A: Encode.txt.");	NEWLINE;
	SPACE;	printf("Encoded filename_B: Encode Text.huf.");	NEWLINE;
	NEWLINE;
}


//w存放n个字符的权值(w>0)，构造赫夫曼树HT，并求出n个字符的赫夫曼编码HC
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, unsigned int *w, unsigned n)
{
	unsigned i,m;
	unsigned s1,s2;
	HuffmanTree p;

	m=2*n-1;
	//分配结点空间
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	//初始化（不使用0结点以方便计算）
	//0结点存放最大权值以方便之后取s1 s2
	HT->weight=MAX_N;		
	HT->lchild=HT->rchild=HT->parent=0;
	for(p=HT+1,i=1;i<=n;i++,p++,w++)
	{
		p->weight=*w;
		p->lchild=p->rchild=p->parent=0;
	}
	for(;i<=m;i++,p++)
	{
		p->lchild=p->rchild=p->parent=p->weight=0;
	}
	//建造哈夫曼树
	for(i=n+1;i<=m;i++)
	{
		Select(HT,i-1,s1,s2);
		HT[s1].parent=i; HT[s2].parent=i;
		HT[i].lchild=s1; HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	
	/*---从叶子结点到根逆向求每个字符的赫夫曼编码---*/
	char *cd;
	unsigned start,c,f;
	HC=(HuffmanCode)malloc((n+1)*sizeof(char *));
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='\0';
	for(i=1;i<=n;i++)
	{
		start=n-1;
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
		{
			if(HT[f].lchild==c)cd[--start]='0';
			else cd[--start]='1';
		}
		HC[i]=(char *)malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}
	free(cd);
}

//在HT[1...n]选择parent为0且weight最小的两个结点，其序号为s1，s2 (s1.weight<=s2.weight)
void Select(HuffmanTree HT, unsigned y, unsigned &s1, unsigned &s2)
{
	unsigned x;
	s1=s2=0;
	for(x=1;x<=y;x++)
	{
		if(HT[x].parent==0)
		{
			if(HT[x].weight<HT[s1].weight)
				s1=x;
			else continue;
		}
		else continue;
	}
	for(x=1;x<=y;x++)
	{
		if((HT[x].parent==0)&&(x!=s1))
		{
			if(HT[x].weight<HT[s2].weight)
				s2=x;
			else continue;
		}
		else continue;
	}
}

//打印并生成赫夫曼码表
void PrintCode(HuffmanCode HC, Text t)
{
	int i;

	if(HFW == NULL || CharArray == NULL)
	{
		SPACE;
		printf("Error: NO CODED");
		NEWLINE;	return;
	}

	//打印并生成密码表
	FILE *codep = fopen("Code.txt", "wb");

	NEWLINE;
	SPACE;	printf("The Huffman Coding Schedule is as follows:");	NEWLINE;
	SPACE;	printf("字符(ASCII码)	权值	编码");					NEWLINE;
	for(i = 0; i < t.ch_quantity; i++)
	{
		SPACE;
		if(CharArray[i] == (int)'\n')
			printf("\\n(%3d)	%d	%s", CharArray[i], HFW[i], HC[i+1]);
		else if(CharArray[i] == (int)'\t')
			printf("\\t(%3d)	%d	%s", CharArray[i], HFW[i], HC[i+1]);
		else
		{
			printf("%2c(%3d)	%d	%s", CharArray[i], CharArray[i], HFW[i], HC[i+1]);
		}
		NEWLINE;	NEWLINE;

		//写入Code.txt
		if(CharArray[i] == (int)'\n')
			fputs("\\n:", codep);
		else if(CharArray[i] == (int)'\t')
			fputs("\\t:", codep);
		else
		{
			fputc(CharArray[i], codep);	fputs(" :", codep);
		}
		fputs(HC[i+1], codep);
		fputs("\n", codep);
	}
}

//译码
void HFT_Decode(HuffmanTree HT, HuffmanCode HC, Text &t)
{
	if(t.flag == 0 || t.mark == 0)
	{
		SPACE;	printf("Error: NO INIT/ENCODE");	NEWLINE;
		return ;
	}
	NEWLINE;
	SPACE;	printf("Original filename: %s", t.filename);	NEWLINE;
	SPACE;	printf("The Code filename: Code.txt");	NEWLINE;
	SPACE;	printf("Encoded  filename: EncodedText.huf");	NEWLINE;
	SPACE;	printf("0-1code  filename: Encoded.txt");	NEWLINE;
	
	FILE *ifp = fopen("EncodedText.huf", "rb");
	FILE *cfp = fopen("Encoded.txt", "wb");
	FILE *ofp = fopen("Decoded.txt", "wb");

	char ch;
	char *st;
	int x, y;
	st = (char *)malloc(t.ch_quantity * sizeof(char));
	unsigned int root, p;
	
	//将huf压缩文件转换为01码存储在cfp指向的文件中(默认为Encoded.txt)
	int hint;
	int i, w;
	char hcode[8];

	ch = fgetc(ifp);
	while(!feof(ifp))
	{
		//hcode数组置零
		for(i = 0; i < 7; i++)
			hcode[i] = '0';
		hcode[7] = '\0';
		//将ch转换为01码暂时存储在hcode中
		hint = (int)ch;
		ch = fgetc(ifp);
		if(feof(ifp) && !X)
		{
			w = 6;
			while(hint != 0)
			{
				hcode[w--] = (hint%2) + '0';
				hint = hint/2;
			}
			if(hcode[6] == '0')
			{
				for(int h = 6; h > 0; h--)
				{
					if(hcode[h-1] == '1')
					{
						hcode[h] = '\0';
						break;
					}
				}
			}
			fputs(hcode, cfp);
			break;
		}
		w = 6;
		while(hint != 0)
		{
			hcode[w--] = (hint%2) + '0';
			hint = hint/2;
		}
		fputs(hcode, cfp);
	}
	fclose(cfp);
	fclose(ifp);

	//译码
	//找到根结点
	for(x = 1; x <= (2*t.ch_quantity-1); x++)
	{
		if(HT[x].parent == 0 && HT[x].weight != 0)
		{
			root = x;	break;
		}
		else
			continue;
	}
	if(x == 2*t.ch_quantity)
	{
		NEWLINE;	SPACE;	printf("Error.");	return;
	}

	FILE *cfp2 = fopen("Encoded.txt", "r");
	while((ch = getc(cfp2)) != EOF)
	{
		x = 0;
		p = root;
		while(HT[p].lchild != 0 || HT[p].rchild != 0)
		{

			if(ch == '0')
			{
				st[x++] = ch;
				p = HT[p].lchild;
			}
			else
			{
				st[x++] = ch;
				p = HT[p].rchild;
			}
			if(HT[p].lchild != 0 || HT[p].rchild != 0)
				ch = getc(cfp2);
			if(ch == EOF)
					break;
		}
		st[x] = '\0';
		for(y = 0; y < t.ch_quantity; y++)
		{
			if(strcmp(st, HC[y+1]) == 0)
			{
				fputc(CharArray[y], ofp);
				break;
			}
		}
	}
	fclose(cfp2);
	fclose(ofp);

	SPACE;	printf("Completely the decode filename: Decoded.txt");	NEWLINE;
	NEWLINE;
}
