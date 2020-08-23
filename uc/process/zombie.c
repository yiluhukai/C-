/*
 *
 *
 *
 *	僵尸进程
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
		// getchar();

		exit(-1);
	}else{
		// 等待子进程终止
		getchar();
		wait(&s);
		sleep(10);
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
