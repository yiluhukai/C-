/*
 *
 *	向文件中写入内容
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    //打开文件
	FILE * f = fopen("data.txt","w");
	if(NULL == f){
		printf("打开文件失败\n");
	}
	//准备写入文件的内容
	//char * str= "hello world!";
	//fwrite(str,sizeof(char),strlen(str),f);
	int a =97;
	fwrite(&a,sizeof(int),1,f);
	//关闭文件
	fclose(f);
	f=NULL;
	return 0;
}
