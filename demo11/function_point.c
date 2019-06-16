/*
 *
 *	函数指针
 *
 */
#include <stdio.h>

int add(int a,int b){

	return a+b;
}
int main(){
	//声明一个函数指针
	int (*p) (int,int) = NULL;
	//打印add函数的地址
	printf("%p\n",add);
	printf("%p\n",&add);
	//打印main函数的地址
	printf("%p\n",main);
	printf("%p\n",&main);

	//将函数指针指向函数的地址
	
	p = add;
	// p  *p的是同一个地址
	printf("%p\n",p);
	printf("%p\n",*p);
	// 使用函数指针调用一个函数
	
	//int  sum  =  (*p)(2,3); 
	//
	int sum = p(2,3);
	printf("%d\n",sum);
}
