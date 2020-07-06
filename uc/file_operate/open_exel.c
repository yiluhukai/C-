/*
 *	以写的的方式打开文件，如果文件不存在，创建文件，文件存在则报错
 *
 */
#include "t_file.h"

int main(int argc,char* argv[]){
	int flag = O_WRONLY|O_CREAT|O_EXCL;
	int file = open(argv[1],flag,0664);
	if(file == -1){
		perror("open");
		return -1;
	}
	printf("open file successfully");

	close(file);	
	return 0;
}
