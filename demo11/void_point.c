/*
 *	空指针 
 */
#include <stdio.h>

int main(){
	
	int i=0x21323334;
	//将char×类型的指针只想一个整形指针。

	char* p =( char *) &i;		
    // 字符c对应的scill码为34.
	printf("%c\n",*p);	
	printf("%c\n",*(p+1)); // 33 --> 3
	printf("%c\n",*(p+2)); // 32 --> 2
	printf("%c\n",*(p+3)); // 33 --> 1
	char c = 'A';
	void * pa= &c; // 将字符类型赋值给空指针
	printf("c=%c\n",*(char *)pa);
	return 0;

}
