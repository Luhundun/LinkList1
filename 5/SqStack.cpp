#include"Stack.h"
void InitStack(SqStack &S)
{
    S.base=(SElemType *)malloc(STACKINITSIZE*sizeof(SElemType));
	if(!S.base) exit(-2);
	S.top=S.base;
	S.stacksize=STACKINITSIZE;
}//��ʼ��ջ

void Push(SqStack &S,SElemType e)
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*(sizeof(SElemType)));
	    if(!S.base) exit(-2);
	    S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
}//��ջ

void Pop(SqStack &S,SElemType &e)
{ 
    if(S.top==S.base) printf("����!\n");
	else
	{
		e=*S.top--;
	}
}//��ջ

SElemType GetTop(SqStack S)
{
	return *(S.top-1);
}//ȡջ��Ԫ��

int StackEmpty(SqStack S)
{
	if(S.base==S.top)
		return 1;
	else return 0;
}//�ж��Ƿ�Ϊ��ջ

void VisitStack(SqStack S)
{
	if(S.base==S.top)
		printf("��ջ����");
	while(S.base!=S.top)
	{
		printf("| %3d  |\n",*(S.top-1));
		S.top--;
	}
}//����ջ

