/*
 *
 *	动态分配内存
 *
 */

#include <stdio.h>
#include <stdlib.h>


int main(){
	//分配内存空间
	int *p =(int *) malloc(sizeof(int));
	*p =200;
	printf("%d\n",*p);
	//释放内存
	free(p);
	//将指针指向NULL,防止野指针
	
	p = NULL;
	return 0;
}
