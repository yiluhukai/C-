/*
 *
 *
 *	声明函数指针类型
 *
 */

#include <stdio.h>
int add( int a,int b){


	return a+b;
}

int sub(int a,int b){

	return a-b;
}

int main(){
	//声明一个函数指针类型
	typedef int (*pa)(int ,int);

	//使用该类型去创建函数指针变量
	
	pa p1,p2;
	p1 = add; p2 = sub;
	int sum = p1(2,3);
	int cha = p2(2,3);
	printf("sum = %d,cha = %d\n",sum,cha);
	return 0;
}
