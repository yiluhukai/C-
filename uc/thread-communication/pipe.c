/*
 *
 *	使用无名管道进行父子进程间的通信
 *
 *
 *
 */
#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	// 创建管道
	
	int fds[2];
	int res = pipe(fds);
	char * buff[128];
	char * msg ="hello world";
	int len  = strlen(msg);
	if(res==-1){
		perror("pipe");
		return -1;
	}
	// 创建子进程
	pid_t pid = fork();
	if(pid ==-1){
		perror("fork");
		return -1;
	}

	if(pid == 0){
		close(fds[1]);
		int r = read(fds[0],buff,len);
		close(fds[1]);
		write(1,buff,r);
		write(1,"\n",strlen("\n"));
		exit(1);		
	}else{
		close(fds[0]);
		write(fds[1],msg,len);
		close(fds[1]);
		wait(NULL);		
	}
	return 0;
}

