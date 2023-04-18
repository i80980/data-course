#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 100 
//˳��ջ�ռ�Ĵ洢�� 


//˳��ջ 


typedef int DataType;
//˳��ջԪ������ 
typedef struct{
	DataType *data;
//	˳��ջԪ�ش���ռ��ַ 
	int top;
//	ջ�� 
}SeqStack;
//˳��ջ���� 

void wait()
{
	printf("\n �밴�����...\n");
	getch();
}

int go_on()
{
	int flag=1;
	char choice;
	while(1){
		printf("\n������[Y/N]");
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

//��ʼ��������һ����ջ
void Init_SeqStack(SeqStack *S,int n)
{
	S->data=(DataType*)malloc(n*sizeof(DataType));
	if(S->data==NULL){
		printf("/n �ڴ����ʧ�ܡ�\n");
		exit(1);
	}
	S->top=-1;
 } 
 
//�ж�˳��ջ�Ƿ�Ϊ��
int Empty_SeqStack(SeqStack *S)
{
	if(S->top==-1)
		return(1);
	else
		return(0);
 } 
// �ж�˳��ջ�Ƿ�Ϊ��
int Full_SeqStack(SeqStack *S)
{
	if(S->top==MAXSIZE-1)
		return(1);
	else
		return(0);
 } 
 
// ��ջ������Ԫ��eΪ�µ�ջ��Ԫ��
int Push_SeqStack(SeqStack *S,DataType e) 
{
	if(Full_SeqStack(S)==1){
//		ջ����������ջ
	printf("\nջ����������ջ");
	return(0); 
	}
	else{
		S->top++;
		S->data[S->top]=e;
//		eԪ����ջ
		return(1); 
	}
}


void Push(SeqStack *S)
{
	DataType x;
	int flag=1,push_flag;
	while(flag){
		printf("\n ������Ҫ��ջԪ��:");
		scanf("%d",&x);
		push_flag=Push_SeqStack(S,x);
		if(push_flag==1)
		printf("\n ��ջ�ɹ�.\n");
		else
		printf("\n ��ջʧ��.\n");
		flag=go_on( );
	}
}

/* ��ջ��ɾ��ջ��Ԫ�أ�����*e ������ֵ */
int Pop_SeqStack(SeqStack *S,DataType *e)
{
	if(Empty_SeqStack(S)){ /* ջ�գ����ܳ�ջ */
		printf("\n ջ�գ����ܳ�ջ.\n");
		return(0);
	}
	else{
		*e=S->data[S->top]; /* ջ��Ԫ�ش���*e */
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
			printf("\n ��ջ�ɹ�����ջԪ��Ϊ��%d\n",x);
		else
			printf("\n ��ջʧ��.\n");
		flag=go_on( );
	}
}

/* ȡջ��Ԫ�أ���*e ������ֵ */
int GetTop_SeqStack(SeqStack *S,DataType *e)
{
	if(Empty_SeqStack(S)){ /* ջ�գ�����ȡջ��Ԫ�� */
		printf("\n ջ�գ�����ȡջ��Ԫ��.\n");
		return(0);
	}
	else{
		*e=S->data[S->top];
		return(1);
	}
}

/* ���ջ��Ԫ�� */
void Display_Top(SeqStack *S)
{
	DataType e;
	if(Empty_SeqStack(S)==1)
		printf("\n ջ�գ�û��Ԫ��.\n");
	else{
		GetTop_SeqStack(S,&e);
		printf("\n ջ��Ԫ�أ�");
		printf("%4d\n",e);
	}
}

/* ���ջȫ��Ԫ�� */
void Display_SeqStack(SeqStack *S)
{
	int i;
	if(Empty_SeqStack(S)==1)
		printf("\n ջ�գ�û��Ԫ��.\n");
	else{
		printf("\n ջȫ��Ԫ��");
		printf("\n ջ��<---------------->ջ��\n");
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
		printf("----˳��ջ����̬����ʵ�֣�----\n");
		printf(" 1.......��ջ\n");
		printf(" 2.......��ջ\n");
		printf(" 3.......���ջ��Ԫ��\n");
		printf(" 4.......���ȫ��Ԫ��\n");
		printf(" 0.......�˳�\n");
		printf("------------------------------\n");
		printf("��ѡ��[1/2/3/4/0]:");
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

