/*
 *
 *	使用数组存储对个字符hello
 *
 */


#include <stdio.h>

int main(){

	char str[5];
	for(int i =0 ;i < 5; i++ ){
	
		printf("请输入一个字符：");
		scanf("%c",&str[i]);
		//清除缓存区
		scanf("%*[^\n]");
		scanf("%*c");
	}

	//打印输入的字符
 	for(int i =0;i<5;i++){
		printf("  %c",str[i]);
	}
	printf("\n");
	return 0;
}
