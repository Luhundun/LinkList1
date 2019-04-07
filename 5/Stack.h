#ifndef _STACK_H_ // 意思是：宏开始行，如果还没有定义 _HEADER_One_H_ 则 进入，否则退出
#define _STACK_H_ //定义 
#include<stdio.h>
#include<stdlib.h>
#define STACKINITSIZE 100
#define STACKINCREMENT 10
#define SElemType int
typedef struct{
    SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
#endif // 宏结束行


void InitStack(SqStack &S);//初始化栈

void Push(SqStack &S,SElemType e);//入栈

void Pop(SqStack &S,SElemType &e);//出栈

SElemType GetTop(SqStack S);//取栈顶元素

int StackEmpty(SqStack S);//判断是否为空栈

void VisitStack(SqStack S);//遍历栈
