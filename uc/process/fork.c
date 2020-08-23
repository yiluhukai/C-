/*
 *
 *	创建一个子进程
 *	父进程fork成功会创建一个子进程的pid,子进程调用fork返回0
 *
 */


#include <sys/types.h> 
#include <unistd.h> 
#include  <stdio.h>
int main(){
	pid_t pid;
	pid = fork();

	if(pid == -1){

		perror("fork");
	}	

	if(pid == 0){

		printf("child thread\n");
	}else{
		printf("parent thread\n");
	}
	return 0;

}
