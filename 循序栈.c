#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 100 
//顺序栈空间的存储量 


//顺序栈 


typedef int DataType;
//顺序栈元素类型 
typedef struct{
	DataType *data;
//	顺序栈元素储存空间基址 
	int top;
//	栈顶 
}SeqStack;
//顺序栈类型 

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
		printf("\n继续吗？[Y/N]");
		choice=getche();
		if(choice=='Y'||choice=='y')
			break;
		else if(choice=='N'||choice=='n'){
			flag=0;
			break;
		}
	}
	return(flag);
}

//初始化，构造一个空栈
void Init_SeqStack(SeqStack *S,int n)
{
	S->data=(DataType*)malloc(n*sizeof(DataType));
	if(S->data==NULL){
		printf("/n 内存分配失败。\n");
		exit(1);
	}
	S->top=-1;
 } 
 
//判断顺序栈是否为空
int Empty_SeqStack(SeqStack *S)
{
	if(S->top==-1)
		return(1);
	else
		return(0);
 } 
// 判断顺序栈是否为满
int Full_SeqStack(SeqStack *S)
{
	if(S->top==MAXSIZE-1)
		return(1);
	else
		return(0);
 } 
 
// 入栈，插入元素e为新的栈顶元素
int Push_SeqStack(SeqStack *S,DataType e) 
{
	if(Full_SeqStack(S)==1){
//		栈顶，不能入栈
	printf("\n栈顶，不能入栈");
	return(0); 
	}
	else{
		S->top++;
		S->data[S->top]=e;
//		e元素入栈
		return(1); 
	}
}


void Push(SeqStack *S)
{
	DataType x;
	int flag=1,push_flag;
	while(flag){
		printf("\n 请输入要入栈元素:");
		scanf("%d",&x);
		push_flag=Push_SeqStack(S,x);
		if(push_flag==1)
		printf("\n 入栈成功.\n");
		else
		printf("\n 入栈失败.\n");
		flag=go_on( );
	}
}

/* 出栈，删除栈顶元素，并由*e 返回其值 */
int Pop_SeqStack(SeqStack *S,DataType *e)
{
	if(Empty_SeqStack(S)){ /* 栈空，不能出栈 */
		printf("\n 栈空，不能出栈.\n");
		return(0);
	}
	else{
		*e=S->data[S->top]; /* 栈顶元素存入*e */
		S->top--; 
		return(1);
	}
}

void Pop(SeqStack *S)
{
	DataType x;
	int flag=1,pop_flag;
	while(flag){
		pop_flag=Pop_SeqStack(S,&x);
		if(pop_flag==1)
			printf("\n 出栈成功，出栈元素为：%d\n",x);
		else
			printf("\n 出栈失败.\n");
		flag=go_on( );
	}
}

/* 取栈顶元素，由*e 返回其值 */
int GetTop_SeqStack(SeqStack *S,DataType *e)
{
	if(Empty_SeqStack(S)){ /* 栈空，不能取栈顶元素 */
		printf("\n 栈空，不能取栈顶元素.\n");
		return(0);
	}
	else{
		*e=S->data[S->top];
		return(1);
	}
}

/* 输出栈顶元素 */
void Display_Top(SeqStack *S)
{
	DataType e;
	if(Empty_SeqStack(S)==1)
		printf("\n 栈空，没有元素.\n");
	else{
		GetTop_SeqStack(S,&e);
		printf("\n 栈顶元素：");
		printf("%4d\n",e);
	}
}

/* 输出栈全部元素 */
void Display_SeqStack(SeqStack *S)
{
	int i;
	if(Empty_SeqStack(S)==1)
		printf("\n 栈空，没有元素.\n");
	else{
		printf("\n 栈全部元素");
		printf("\n 栈底<---------------->栈顶\n");
		for(i=0;i<=S->top;i++)
			printf("%6d",S->data[i]);
		printf("\n");
	}
}

main()
{
	SeqStack S;
	char choice;
	int flag=1;
	Init_SeqStack(&S,MAXSIZE);
	do{
		printf("\n");
		printf("----顺序栈（动态数组实现）----\n");
		printf(" 1.......入栈\n");
		printf(" 2.......出栈\n");
		printf(" 3.......输出栈顶元素\n");
		printf(" 4.......输出全部元素\n");
		printf(" 0.......退出\n");
		printf("------------------------------\n");
		printf("请选择[1/2/3/4/0]:");
		choice=getche( );
		switch(choice){
			case '1':Push(&S);break;
			case '2':Pop(&S);break;
			case '3':Display_Top(&S);break;
			case '4':Display_SeqStack(&S);break;
			case '0':flag=0;break;
		}
		wait( );
	}while(flag==1);
}

