/*
 *
 *	pause等待一个信号
 *	
 */
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
void handle(int sid){
	
	printf("sid=%d\n",sid);	
}
int main(){
	// 为了让进程不直接终止，查看pause的返回值
	signal(2,handle);
	int res = pause();
	printf("return value =%d\n",res);
	return 0;
	
}
