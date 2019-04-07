#include<stdio.h>
#include<stdlib.h>
#define SElemType int
typedef struct Snode{
    SElemType data;
	struct Snode *next;
}Snode,*LinkStack;

void InitStack(LinkStack &S)
{
    S=NULL;
}//初始化栈

void Push(LinkStack &S,SElemType e)
{
	LinkStack p;
	p=(LinkStack)malloc(sizeof(Snode));
	p->data=e;
	p->next=S;
    S=p;
}//入栈

void Pop(LinkStack &S,SElemType &e)
{
	LinkStack p=S;
    if(!S) printf("空栈错误!\n");
	else
	{
		S=S->next;
		free(p);
	}
}//出栈

void GetTop(LinkStack S,SElemType &e)
{
	if(!S)
	    printf("空栈错误！");
    else
	{
		e=S->data;
	}
}//取栈顶元素


int StackEmpty(LinkStack S)
{
	if(S)
		return 1;
	else return 0;
}//判断是否为空栈

void VisitStack(LinkStack S)
{
	LinkStack p=S;
	if(!p)
	    printf("空栈！");
	else
	{
	    while(p)
		{
		    printf("| %3d  |\n",p->data);
		    p=p->next;
		}
	}
}//遍历栈

void main()
{
	LinkStack S;
    int e,m;
	InitStack(S);
	printf("请输入栈元素的数量");
    scanf("%d",&m);
	while(m-->0)
	{
	printf("请输入入栈的元素");
	scanf("%d",&e);Push(S,e);
	}	
	VisitStack(S);

	printf("顶端元素出栈后\n");
	Pop(S,e);	VisitStack(S);

	GetTop(S,e);printf("栈顶元素e为%d\n",e);
	if(StackEmpty(S)) printf("现在的栈为空栈\n");
	else printf("现在的栈非空栈\n");
}