#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
	char*  str1 = "hello world";
	char*  str2 = "hello world";
	char arr[]  = "hello world";
	printf("pid = %d\n",getpid());
	// str1的空间分配在哪里
	printf("str1 address =%p\n",&str1);
	// str1的内容在什么位置
	printf("str1 content =%p\n",str1);
	// str1和str2的内容是否相同
	printf("str2 content =%p\n",str2);
	printf("arr content =%p\n",arr);
	printf("arr address=%p\n",&arr);
	getchar();
	return 0;
}
