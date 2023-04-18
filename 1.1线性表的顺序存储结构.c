#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXSIZE 100 	/* 顺序表空间的存储量 */

typedef int DataType;	 /* 顺序表元素类型 */

typedef struct{
	DataType data[MAXSIZE];	 /* 顺序表元素数组 */
	int last; 	/* 顺序表最后一个元素位置 */
}SeqList; 	/* 顺序表类型 */

void wait()
{
	printf("\n 请按任意键...\n");
	getch();
}

int go_on()
{
	int flag=1;
	char choice;
	
	while(1){
		printf("\n 继续吗？[Y/N]");
		choice=getche();
		if(choice=='Y' || choice=='y')
			break;
		else if(choice=='N' || choice=='n'){
			flag=0;
			break;
		}
	}
	return(flag);
}

/* 初始化，构造一个空顺序表 */
SeqList *Init_SeqList( )
{
	SeqList *L;
	
	L=(SeqList *)malloc(sizeof(SeqList));
	if(!L){
		printf("\n 内存分配失败.\n");
		exit(-1);
	}
	L->last=-1;
	return(L);
}

/* 插入元素，在顺序表第 i 个位置之前插入元素 x，即插入在第 i 个位置 */
int Insert_SeqList(SeqList *L,int i,DataType x)
{
int j;
	if(L->last==MAXSIZE-1){ 	/* 表满，不能插入 */
		printf("\n 表满，不能插入.\n");
		return(-1); 	/* 不能插入，返回-1 */
	}
	
if(i<1 || i>L->last+2){ /* 插入位置错，不能插入 */
	printf("\n 插入位置错，不能插入.\n");
	return(0); /* 插入失败，返回 0 */
}

	for(j=L->last;j>=i-1;j--) /* 元素向后移动 */
		L->data[j+1]=L->data[j];
	L->data[i-1]=x; /* 插入元素 x */
	L->last++; /* 表最后位置值增加 1 */
	return(1); /* 插入成功，返回 1 */
} 

void Insert(SeqList *L)
{
	DataType x;
	int i,flag=1,insert_flag;
	
	while(flag){
	printf("\n 请输入要插入元素的位置：");
	scanf("%d",&i);
	printf("请输入要插入元素:");
	scanf("%d",&x);

	insert_flag=Insert_SeqList(L,i,x);

	if(insert_flag==1)
		printf("\n 插入成功.\n");
	else
		printf("\n 插入失败.\n");

	flag=go_on();
	}
}
/* 删除元素，将顺序表第 i 个位置元素删除 */

		
		int Delete_SeqList(SeqList *L,int i)
{
int j;
if(L->last==-1){ /* 表空，不能删除 */
printf("\n 表空，不能删除.\n");
return(-1); /* 删除失败，返回-1 */
}
if(i<1 || i>L->last+1){ /* 删除位置错，不能删除. */
printf ("\n 删除位置错，不能删除.\n");
return(0); /* 删除失败，返回 0 */
}
for(j=i; j<=L->last; j++)
L->data[j-1]=L->data[j]; /* 结点向前移动 */
L->last--; /* last 仍指向最后元素 */
return(1); /* 删除成功，返回 1 */
}
void Delete(SeqList *L)
{
int i,flag=1,delete_flag;
while(flag){
printf("\n 请输入要删除元素的位置：");
scanf("%d",&i);
delete_flag=Delete_SeqList(L,i);
if(delete_flag==1)
printf("\n 删除成功.\n");
else
printf("\n 删除失败.\n");
flag=go_on();
}
}
/* 按值查找元素，在顺序表中查找元素 x，*/
/* 查找成功，返回 x 的位置序号，查找失败，返回-1 */
int Locate_SeqList(SeqList *L, DataType x)
{
int i=0;
while(i<=L->last && L->data[i]!= x)
i++;
if(i>L->last)
return(-1); /* 查找失败，返回-1 */
else
return(i+1); /* 查找成功，返回 x 的位置序号 */
}
void Locate(SeqList *L)
{
DataType x;
int flag=1,locate_flag;
while(flag){
printf("\n 请输入要查找元素：");
scanf("%d",&x);
locate_flag=Locate_SeqList(L,x) ;
if(locate_flag>0)
printf("\n 查找成功，%d 是第 %d 个元素.\n",x,locate_flag);
else
printf("\n 查找失败，没有元素 %d.\n",x);
flag=go_on();
}
}
/* 输出顺序表 */
void Display_SeqList(SeqList *L)
{
int i;
printf("\n 顺序表全部元素\n");
for(i=0;i<=L->last;i++)
printf("%4d",L->data[i]);
printf("\n");
}
main()
{
SeqList *L;
char choice;
int flag=1;
L=Init_SeqList( );
do{
printf("\n");
printf("----顺序表（静态数组实现）----\n");
printf(" 1.......插入元素\n");
printf(" 2.......删除元素\n");
printf(" 3.......查找元素\n");
printf(" 4.......输出元素\n");
printf(" 0.......退出\n");
printf("------------------------------\n");
printf("请选择[1/2/3/4/0]:");
choice=getche();

	switch(choice){
case '1':Insert(L);break;
case '2':Delete(L);break;
case '3':Locate(L);break;
case '4':Display_SeqList(L);break;
case '0':flag=0;break;
}
wait();
}while(flag==1);
}		
		
