/*
 *
 *	创建一个管道文件
 *
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char * argv[]){
	
	// 创建管道文件
	
	int res = mkfifo(argv[1],0644);

	if(res == -1){
		perror("mkfifo");
		return -1;
	}

	printf("创建管道文件%s成功",argv[1]);


	return 0;
}
