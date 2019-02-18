/*
 *
 *从键盘上输入两个数，然后计算两个数的和并输出
 *
 */

#include <stdio.h>
int main()
{
	//声明两个变量来接受输入的值
	int a=0,b=0;
	int sum=0;
	//接受用户的输入，scanf接受多个输入的时候默认使用空格来分割，但是
	//我们可以指定分隔符为，
	printf("请输入两个数，之间用,分割：");
	scanf("%d,%d",&a,&b);
	sum=a+b;
	printf("sum=%d\n",sum);
	return 0;
}
