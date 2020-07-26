/*
 *
 *
 *	使用execle替换进程的映像
 *
 *
 *
 */
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(){

	char * envs[] = {"caption=beijing",NULL};
	pid_t pid = fork();
	if(pid == -1){
		perror("fork");
		return -1;
	}
	if(pid == 0){
		// 给子进程添加环境变量
		setenv("name","lijunjie",1);
		//execl("./tenv","./tenv",NULL);
		//使用我们之前的可执行程序替换原来的子进程映像
		execle("./tenv","./tenv",NULL,envs);
	}else{
		wait(NULL);
	}
	return 0;
}
