#ifndef _STACK_H_ // ��˼�ǣ��꿪ʼ�У������û�ж��� _HEADER_One_H_ �� ���룬�����˳�
#define _STACK_H_ //���� 
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
#endif // �������


void InitStack(SqStack &S);//��ʼ��ջ

void Push(SqStack &S,SElemType e);//��ջ

void Pop(SqStack &S,SElemType &e);//��ջ

SElemType GetTop(SqStack S);//ȡջ��Ԫ��

int StackEmpty(SqStack S);//�ж��Ƿ�Ϊ��ջ

void VisitStack(SqStack S);//����ջ
