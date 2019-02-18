/*
 * 格式化输出变量
 */

#include <stdio.h>

int main()
{
	char i='a';
	int  a=100;
	float f=1.22;
	//输出浮点数变量f
	printf("f=%f\n",f);
	//输入无符号的10进制整数
	printf("a=%u\n",a);
	//以十进制的方式输出字符i
	printf("i=%d\n",i);
	//以十六进制的方式输出变量i
	printf("i=%x\n",i);
	//以字符的方式输出变量i
	printf("i=%c\n",i);
	//以八进制的方式输出变量i
	printf("i=%o\n",i);
	return 0;
}
