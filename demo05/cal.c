/*
 *	实现一个简单的计算器，可以进行+、-、*、/、%
 *
 */

#include <stdio.h>

int main()
{	
	int a=0,b=0;
	char oper = 0;
	printf("请输入需要计算的表达式");
	scanf("%d%c%d",&a,&oper,&b);
	switch(oper){
		case '+':		
			printf("%d%c%d=%d",a,oper,b,a+b);
			break;
		case '-':		
			printf("%d%c%d=%d",a,oper,b,a-b);
			break;
		case '*':		
			printf("%d%c%d=%d",a,oper,b,a*b);
			break;
		case '/':
			printf("%d%c%d=%f",a,oper,b,a/(float)b);
			break;	
		case '%':
			//%% 相当%
			//printf("%d%%%d=%d,a,oper,b",a,b,a%b)
			printf("%d%c%d=%d",a,oper,b,a%b);
			break;
		default:
			printf("输入有错误！");	
	}
	return  0;
}
