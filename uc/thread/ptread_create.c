/*
 *
 *
 *	在进程中创建一个新的线程,并获取线程的pid
 *
 */

#include <pthread.h> 
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void *doit(void *arg){
	printf("this is %s thread,pid=%d\ttid=%lu\n",(char *)arg,getpid(),pthread_self());
	return NULL;
}
int main(){
	//创建一个新的线程
	pthread_t  pid;
	int r = pthread_create(&pid,NULL,doit,"NEW");
	if(r!=0){
		perror("pthread_create");
		return -1;
	}
	//  在主线程中执行代码
	//  防止主线程提前退出
	sleep(3);
	doit("main");
	
	return 0;
}
