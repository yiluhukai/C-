/*
 *	使用lseek函数的修改偏移位置的例子
 *
 */
#include "t_file.h"

int main(int argc,char* argv[]){
	int flag = O_RDONLY;
	int file = open(argv[1],flag);
	if(file == -1){
		perror("open");
		return -1;
	}
	// 修改文件的offset
	lseek(file,6,SEEK_SET);
	
	int buff;
	read(file,&buff,sizeof(buff));
	// 输出buff的内容
	char *p =(char *)&buff;
	printf("%c",*p++);
	printf("%c",*p++);
	printf("%c",*p++);
	printf("%c",*p++);
	printf("\n");
	close(file);	
	return 0;
}
