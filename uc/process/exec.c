/*
 *
 *
 *  	使用exec替换进程的映像
 *
 *
 *
 */
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
int main(){ 
	int status; 
	char *  args[] ={"ps","-o","pid,ppid,pgrp,comm",NULL};
	pid_t  pid = fork();

	if(pid == -1){
		printf("fork");
		return -1;
	}
	if(pid == 0){
		//替换进程映像
	//	int res=execlp("ps","ps","-o","pid,ppid,pgrp,comm",NULL);
	//	int res=execl("/usr/bin/ps","/usr/bin/ps","-o","pid,ppid,pgrp,comm",NULL);
		
		int res=execvp("ps",args);
			//替换成功不会执行下面的代码
		if(res ==-1){
			perror("execl");
			return -1;	
		}
	}else{
		wait(&status);
	}
	return 0;
}
