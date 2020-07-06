/*
 *	实现一个类似cat的命令
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
	char buff[128];
	ssize_t  r;
	// 等于0代表到达文件的末尾
	while((r=read(file,buff,128))!=0){
		write(STDOUT_FILENO,buff,r);		
	}
	close(file);	
	return 0;
}
