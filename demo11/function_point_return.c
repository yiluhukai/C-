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

//接受一个字符串，根据字符串的不同返回不同的函数
pa useAmethod(char oper){
	if(oper =='+'){
		return add;
	}else{
		return sub;
	}
}
//接受第三个参数为一个函数指针
int computed(int a,int b,char operator){
	//调用上面的方法
	pa method = useAmethod(operator);

	//调用method方法
	
	return method(a,b);
	
}


int main(){
	//传入一个函数作为参数，函数会根据回调函数的不同进行不同的操作
	int sum =computed(2,3,'+');
	int cha =computed(2,4,'-');

	printf("sum=%d\n",sum);
	printf("cha=%d\n",cha);
	return 0;
}
