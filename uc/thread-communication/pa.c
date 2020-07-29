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
	char * msg ="hello world\n";
	int  fd = open(argv[1],O_WRONLY);
	if(fd == -1){
		perror("open");
		return -1;
	}
	// 向文件写入内容，会阻塞当前进程
	write(fd,msg,strlen(msg));
	close(fd);
	return 0;
}
