/*
 * 在计算机中，数是以补码的形式存在的 
 */

#include <stdio.h>

int main()
{
	//默认生命的是一个有符号的整形
	int i=-2;
	//以十六机制的方式输出变量i
	//i=oxfffffffe
	//-2的原码为 1000 0000 0000 0000 0000 0000 0000 0010
	//符号位不变，其他位取反  最后加1
	//补码为     1111 1111 1111 1111 1111 1111 1111 1101
	/十六进制    f     f    f    f    f    f    f    e
	printf("i=ox%x\n",i);
	return 0;
}
