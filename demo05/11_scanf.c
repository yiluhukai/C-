/*
 *	输入缓存区
 *
 */

#include <stdio.h>
int main(){
	char c = 0;
	for(int i =0 ; i < 5; i++ ){
		printf("请输入一个字符");
		//使用%c采用输入缓存，因为回车是一个字符	
		scanf("%c",&c);
		printf("c=%c\n",c);
		//我们每次输入时，输入的是一个字符和回车建，第二次输入的时候从缓存区读取的是回车键。
		//清理\n之前的内容
		scanf("%*[^\n]");
		//清除\n
		scanf("%*c");
	}
	return 0;
}
