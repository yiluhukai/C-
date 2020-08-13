/*
 *
 *	使用pause(2)和alarm(2)实现sleep(3)的功能那个 
 *
 */
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void doit(int signal_id){
}
unsigned int tsleep(unsigned int second){
	// 闹钟信号处理函数不会打断进程
	signal(SIGALRM,doit);
	alarm(second);
	pause();
	//  取消之前的闹钟并返回剩余的时间
	return alarm(0);

}


int main(){

	while(1){
		tsleep(2);
		printf("hello\n");
	}

	return 0;

}
