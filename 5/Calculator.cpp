#include"Stack.h"
#include"Calculate.h"

int Proceed(char theta1,char theta2)   //'>'= 1  '='=0 '<'=-1
{
    if(theta1=='*'||theta1=='/')
	{
		if(theta2!='(')
			return 1;
		else 
			return 0;
	}
	else if(theta1=='+'||theta1=='-')
	{
		if(theta2!='('||theta2!='*'||theta2!='/')
			return 1;
		else
			return -1;
	}
	else if(theta1=='(')
	{
		if(theta2==')')
			return 0;
		else if(theta2!='#')
			return -1;
	}
	else if(theta1==')')
		return 1;
	else
	{
		if(theta2!='#')
			return -1;
		else return 0;
	}

	return 0;
}

int Calcul(int a,int theta,int b)
{
	switch(theta)
	{
	case 1: return a+b;break;
	case 2: return b-a;break;
	case 3: return a*b;break;
	case 4: return b/a;break;
	}
	return 0;
}

int OPERATEchangetoInt(char c)
{
	if(c=='+')
		return 1;
	else if(c=='-')
		return 2;
    else if(c=='*')
		return 3;
    else if(c=='/')
		return 4;
    else if(c=='(')
		return 5;
    else if(c==')')
		return 6;
	else if(c=='#')
		return 7;
	else if(c>='0'&&c<='9')
		return 0;
	else
		return -1;
}

char IntchangetoOPERATE(int c)
{
	if(c==1)
		return '+';
	else if(c==2)
		return '-';
    else if(c==3)
		return '*';
    else if(c==4)
		return '/';
    else if(c==5)
		return '(';
    else if(c==6)
		return ')';
	else if(c==7)
		return '#';
	return NULL;
}

int Evaluate_Expression()
{
	SqStack OPTR,OPED;
	InitStack(OPTR);
	InitStack(OPED);
    Push(OPTR,7);   //把#放入操作符栈的底端
	char c;
	int a,b,theta;
	printf("请输入表达式：");
	c=getchar();
	while( c!='#'||GetTop(OPTR)!=7)
	{
		if(OPERATEchangetoInt(c)==0)
		{
			Push(OPED,c-'0');
			c=getchar();
		}
		else if(OPERATEchangetoInt(c)>0)
		{
			switch(Proceed(IntchangetoOPERATE(GetTop(OPTR)),c))
			{
			case -1:  Push(OPTR,OPERATEchangetoInt(c));c=getchar();break;
			case 0:   Pop(OPTR,a);c=getchar();break;
			case 1:
				Pop(OPTR,theta);
				Pop(OPED,a);
				Pop(OPED,b);
				Push(OPED,Calcul(a,theta,b));break;
			}
		}
	}

	return GetTop(OPED);
}
