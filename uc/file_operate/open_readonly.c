/*
 *	以只读的方式打开文件
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
	printf("open file successfully");

	close(file);	
	return 0;
}
