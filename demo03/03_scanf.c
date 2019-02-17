/*
 * 使用scanf函数输入值到内存
 */

#include <stdio.h>

int main()
{
	//打印变量的初始值
	int i = 10;
	char c = 0;
	printf("i=%d\n",i);
	//以16进制的方式输入一个值
	printf("请输入一个十六进制的数:");
//	scanf("%x",&i);
	//打印输入后的变量值
//	printf("i=%d\n",i);	
	printf("请输入一个字符:");
	scanf("%c",&c);
	printf("c=%c",c);
	return 0;
}
