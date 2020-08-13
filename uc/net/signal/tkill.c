/*
 *
 *
 *	实现类似kill的命令：tkill  9 pid;
 *
 */
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
int main(int argc,char *argv[]){	
	int signal_num = atoi(argv[1]);
	int pid = atoi(argv[2]);

	int res = kill(pid,signal_num);
	if(res ==-1){
		perror("kill");
		return -1;
	}
	//向自己发送信号
	//kill(getpid(),signal_num); 
	return 0;
}
