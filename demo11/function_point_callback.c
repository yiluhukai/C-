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
//声明一个函数指针类型
typedef int (*pa)(int ,int);

//接受第三个参数为一个函数指针
int computed(int a,int b,pa p){
	return p(a,b);
}
int main(){
	//传入一个函数作为参数，函数会根据回调函数的不同进行不同的操作
	int sum =computed(2,3,add);
	int cha =computed(2,4,sub);

	printf("sum=%d\n",sum);
	printf("cha=%d\n",cha);
	return 0;
}
