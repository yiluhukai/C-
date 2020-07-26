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
		printf("parent process....%d\n",getppid());
		getchar();
		printf("parent process....%d\n",getppid());

	}else{
	 	// 等待子进程终止
		printf("parent sleep has died\n");
		sleep(1);
	}
	return 0;
}
