/*
 *
 *	注册信号处理函数
 *
 */

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
void doit(int signal_num){
	printf("signal=%d\n",signal_num);
}


int main(){
	signal(2,doit);
	// The signals SIGKILL and SIGSTOP cannot be caught or ignored. 
	signal(9,doit);
	
	pid_t  pid = fork();

	if(pid == -1){
		perror("fork");
		return -1;
	}
	if(pid == 0){
		//  kill -2 pid in shell
		printf("pid=%d\n",getpid());
		while(1){
		}
	}else{
	
		wait(NULL);
	}

	return 0;
}
