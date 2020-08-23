/*
 *
 *
 *
 *	等待子进程终止
 *
 *
 *
 *
 */
 
#include <sys/wait.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>
int  main(void){
	//  创建一个子进程
	int s;
	pid_t  pid = fork();

	if( pid == -1){
		perror("fork");
		return -1;
	}
	if( pid ==0){
		printf("child process....%d\n",getpid());
		int c =getchar();
		printf("c=%d\n",c);

		exit(-1);
	}else{
	 	// 等待子进程终止
		//waitpid(-1,&s,0);
		//非阻塞
		pid_t t = waitpid(-1,&s,WNOHANG);
		if(t == 0){
			printf("no child thread died\n");
			return 0;
		}
		printf("parent process.....\n");

		if(WIFEXITED(s)){
			printf("normal terminal,status = %d\n",WEXITSTATUS(s));
		}

		if(WIFSIGNALED(s)){
			printf("signal terminal,signal number =%d\n",WTERMSIG(s));
		}
	}
	return 0;
}
