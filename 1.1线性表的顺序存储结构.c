#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXSIZE 100 	/* ˳���ռ�Ĵ洢�� */

typedef int DataType;	 /* ˳���Ԫ������ */

typedef struct{
	DataType data[MAXSIZE];	 /* ˳���Ԫ������ */
	int last; 	/* ˳������һ��Ԫ��λ�� */
}SeqList; 	/* ˳������� */

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
		printf("\n ������[Y/N]");
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

/* ��ʼ��������һ����˳��� */
SeqList *Init_SeqList( )
{
	SeqList *L;
	
	L=(SeqList *)malloc(sizeof(SeqList));
	if(!L){
		printf("\n �ڴ����ʧ��.\n");
		exit(-1);
	}
	L->last=-1;
	return(L);
}

/* ����Ԫ�أ���˳���� i ��λ��֮ǰ����Ԫ�� x���������ڵ� i ��λ�� */
int Insert_SeqList(SeqList *L,int i,DataType x)
{
int j;
	if(L->last==MAXSIZE-1){ 	/* ���������ܲ��� */
		printf("\n ���������ܲ���.\n");
		return(-1); 	/* ���ܲ��룬����-1 */
	}
	
if(i<1 || i>L->last+2){ /* ����λ�ô����ܲ��� */
	printf("\n ����λ�ô����ܲ���.\n");
	return(0); /* ����ʧ�ܣ����� 0 */
}

	for(j=L->last;j>=i-1;j--) /* Ԫ������ƶ� */
		L->data[j+1]=L->data[j];
	L->data[i-1]=x; /* ����Ԫ�� x */
	L->last++; /* �����λ��ֵ���� 1 */
	return(1); /* ����ɹ������� 1 */
} 

void Insert(SeqList *L)
{
	DataType x;
	int i,flag=1,insert_flag;
	
	while(flag){
	printf("\n ������Ҫ����Ԫ�ص�λ�ã�");
	scanf("%d",&i);
	printf("������Ҫ����Ԫ��:");
	scanf("%d",&x);

	insert_flag=Insert_SeqList(L,i,x);

	if(insert_flag==1)
		printf("\n ����ɹ�.\n");
	else
		printf("\n ����ʧ��.\n");

	flag=go_on();
	}
}
/* ɾ��Ԫ�أ���˳���� i ��λ��Ԫ��ɾ�� */

		
		int Delete_SeqList(SeqList *L,int i)
{
int j;
if(L->last==-1){ /* ��գ�����ɾ�� */
printf("\n ��գ�����ɾ��.\n");
return(-1); /* ɾ��ʧ�ܣ�����-1 */
}
if(i<1 || i>L->last+1){ /* ɾ��λ�ô�����ɾ��. */
printf ("\n ɾ��λ�ô�����ɾ��.\n");
return(0); /* ɾ��ʧ�ܣ����� 0 */
}
for(j=i; j<=L->last; j++)
L->data[j-1]=L->data[j]; /* �����ǰ�ƶ� */
L->last--; /* last ��ָ�����Ԫ�� */
return(1); /* ɾ���ɹ������� 1 */
}
void Delete(SeqList *L)
{
int i,flag=1,delete_flag;
while(flag){
printf("\n ������Ҫɾ��Ԫ�ص�λ�ã�");
scanf("%d",&i);
delete_flag=Delete_SeqList(L,i);
if(delete_flag==1)
printf("\n ɾ���ɹ�.\n");
else
printf("\n ɾ��ʧ��.\n");
flag=go_on();
}
}
/* ��ֵ����Ԫ�أ���˳����в���Ԫ�� x��*/
/* ���ҳɹ������� x ��λ����ţ�����ʧ�ܣ�����-1 */
int Locate_SeqList(SeqList *L, DataType x)
{
int i=0;
while(i<=L->last && L->data[i]!= x)
i++;
if(i>L->last)
return(-1); /* ����ʧ�ܣ�����-1 */
else
return(i+1); /* ���ҳɹ������� x ��λ����� */
}
void Locate(SeqList *L)
{
DataType x;
int flag=1,locate_flag;
while(flag){
printf("\n ������Ҫ����Ԫ�أ�");
scanf("%d",&x);
locate_flag=Locate_SeqList(L,x) ;
if(locate_flag>0)
printf("\n ���ҳɹ���%d �ǵ� %d ��Ԫ��.\n",x,locate_flag);
else
printf("\n ����ʧ�ܣ�û��Ԫ�� %d.\n",x);
flag=go_on();
}
}
/* ���˳��� */
void Display_SeqList(SeqList *L)
{
int i;
printf("\n ˳���ȫ��Ԫ��\n");
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
printf("----˳�����̬����ʵ�֣�----\n");
printf(" 1.......����Ԫ��\n");
printf(" 2.......ɾ��Ԫ��\n");
printf(" 3.......����Ԫ��\n");
printf(" 4.......���Ԫ��\n");
printf(" 0.......�˳�\n");
printf("------------------------------\n");
printf("��ѡ��[1/2/3/4/0]:");
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
		
