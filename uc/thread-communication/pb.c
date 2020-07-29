/*
 *
 *
 *	创建一个进程向管道文件中写入数据
 *
 *
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(int argc,char * argv[]){
	
	char  buff[128];

	int  fd = open(argv[1],O_RDONLY);

	if(fd == -1){
		perror("open");
		return -1;
	}
	// 向文件写入内容，会阻塞当前进程
	int r =read(fd,buff,128);
	write(1,buff,r);
	close(fd);
	return 0;
}
