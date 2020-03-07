/*
 *	端错误的产生
 */

#include <stdio.h>

int main(void){
	int var_i = 100;
	int * p ; // 野指针指向的内容是不确定的，有可能发生端错误
	printf("%p\n",p);
	//int * p=&var_i;
	//p=(unsigned int)0x00003000;
	*p=300;
	printf("%d\n",*p); 
	return 0;
}

