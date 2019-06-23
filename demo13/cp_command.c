/*
 *
 *
 *	实现类似cp的指令。
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char * argv[]){
    if(argc < 3){
		printf("参数个数不正确!");
		return -1;
	}
    FILE * f =fopen(argv[1],"r");
	if(!f){
	
		printf("要复制的文件不存在!");
		return -1;
	}
	FILE * fi = fopen(argv[2],"w");
	int c = 0;
	while(( c = getc(f)) !=EOF){
		putc(c,fi);		
    }
    printf("复制文件成功");
	//关闭文件
	fclose(f);
	fclose(fi);
	fi =NULL;
	f = NULL;
	return 0;
}
