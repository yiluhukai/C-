/*
 *
 *	使用getc();
 *
 */


#include <stdio.h>
#include <stdlib.h>
int main(){

	//打开一个文件
	FILE* f =fopen("hello.txt","r+");
	if(!f){
		printf("打开文件失败\n");
		exit(0);
	}
	printf("打开文件成功\n");
	int c =0;
	while((c =getc(f))!=EOF){
		printf("%c\n",c);
	}
	//写入文件内容
	//
	int s ='!';
	putc(s,f);
	fclose(f);
	return 0;
}
