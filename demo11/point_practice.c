/*
 *
 *	二级指针练习：实现一个函数，函数中讲×max指针只想两个较大的数中的一个。
 *	
 */

#include <stdio.h>

void func(int *a,int *b,int ** max){
	if(*a > *b){
		*max = a;
	}else{
		*max = b;
	}
}
int main(){
	
	int a = 0; int b =0;

	scanf("%d,%d",&a,&b);
	int *pmax = NULL;
	func(&a,&b,&pmax);
	printf("*pmax=%d\n",*pmax);
	return 0;
}
