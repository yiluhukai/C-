/*
 *
 *
 *	获取未觉信号集
 *
 *
 */
#include <stdio.h>
#include <signal.h> 
#include <unistd.h>
void doit(int sig_num){
	printf("sig_num=%d,receive ok\n",sig_num);
}
int main(){
	// 设置信号处理函数
	signal(2,doit);
	signal(45,doit);
	signal(9,doit);
	sigset_t set,old_set,pending_set;
	//初始化set
	sigemptyset(&set);
	// 添加2号信号到set
	sigaddset(&set,2);
	sigaddset(&set,45);
	//  9号信号不可以被阻塞
	sigaddset(&set,9);
	int res = sigprocmask(SIG_BLOCK,&set,&old_set);
	if(res == -1){
		perror("sigprocmask");
		return -1;
	}

	while(1){
		// 当受到被阻塞的信号后，放入未觉队列中
		//  获取未决信号集
		sigpending(&pending_set);

		// 假如发送的是2号型号，检测2号信号是不是未决信号，
		// 可以判断其是不是set的成员
		int r= sigismember(&pending_set,2);
		if(r==1){
			printf("2号信号在未决队列中\n");
		}
		sleep(2);
	}
	return 0;
}
