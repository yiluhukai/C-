/*
 *
 *
 * 函数的返回值设置为函数指针类型，这样子可以将一个函数作为返回值
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

pa operators[127];

// 初始化数组中的函数 

void initArray(){
	operators['+'] = add;
	operators['-'] = sub;
}


int computed(int a,int b,char operator){
	//根据操作符号从数组中取出对应的方法。
	pa method = operators[operator];

	//调用method方法
	
	return method(a,b);
	
}


int main(){

	//初始化函数指针数组
	initArray();
	//传入一个函数作为参数，函数会根据回调函数的不同进行不同的操作
	int sum =computed(2,3,'+');
	int cha =computed(2,4,'-');

	printf("sum=%d\n",sum);
	printf("cha=%d\n",cha);
	return 0;
}
