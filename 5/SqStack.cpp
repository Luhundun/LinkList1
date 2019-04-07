#include"Stack.h"
void InitStack(SqStack &S)
{
    S.base=(SElemType *)malloc(STACKINITSIZE*sizeof(SElemType));
	if(!S.base) exit(-2);
	S.top=S.base;
	S.stacksize=STACKINITSIZE;
}//初始化栈

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
}//入栈

void Pop(SqStack &S,SElemType &e)
{ 
    if(S.top==S.base) printf("错误!\n");
	else
	{
		e=*S.top--;
	}
}//出栈

SElemType GetTop(SqStack S)
{
	return *(S.top-1);
}//取栈顶元素

int StackEmpty(SqStack S)
{
	if(S.base==S.top)
		return 1;
	else return 0;
}//判断是否为空栈

void VisitStack(SqStack S)
{
	if(S.base==S.top)
		printf("空栈错误！");
	while(S.base!=S.top)
	{
		printf("| %3d  |\n",*(S.top-1));
		S.top--;
	}
}//遍历栈

