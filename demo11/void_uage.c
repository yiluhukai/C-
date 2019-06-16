/*
 *	空指针的使用:实现一个函数，可以接受任何类型的指针，打印输出该指针指向变量的值。
 *
 */

# include <stdio.h>

typedef enum {
	Integer,Char
}Type;

void myprint(void * p, Type s){
	if(s == Integer){
		printf("%d\n",*(int *)p);
	}else{
		printf("%c\n",*(char *)p);
	}
}

int main(){
	int a = 10;
	char c ='A';
	myprint(&a,Integer);
	myprint(&c,Char);
	return 0;
}
