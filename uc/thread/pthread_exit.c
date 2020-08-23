/*
 *
 *
 *	线程的终止和汇合
 *
 *
 */
#include <pthread.h> 
#include <stdio.h>
#include <unistd.h>
void* func1(void* retval){
	printf("thread1 is running\n");
	sleep(2);
	return (void*)1;
}
void* func2(void* retval){
	printf("thread2 is running\n");
	sleep(3);
	pthread_exit((void*)3);
}

void* func3(void* retval){
	while(1){
		printf("thread3 is running\n");
		sleep(1);
	}
	pthread_exit(NULL);

}

int main(){
	pthread_t thread1,thread2,thread3;
	void * retval;
	pthread_create(&thread1,NULL,func1,NULL);
	// 等待目标线程的终止,是同步的执行的，所以又叫线程的同步
	pthread_join(thread1,&retval);
	printf("thread1 exit code = %d\n",(int)retval);

	pthread_create(&thread2,NULL,func2,NULL);
	// 等待目标线程的终止,是同步的执行的，所以又叫线程的同步
	pthread_join(thread2,&retval);
	printf("thread2 exit code = %d\n",(int)retval);
	//  
	pthread_create(&thread3,NULL,func3,NULL);
	sleep(3);
	//  取消thread3线程
	pthread_cancel(thread3);

	pthread_join(thread3,&retval);
	printf("thread3 exit code = %d\n",(int)retval);

	printf("main thread exit\n");
	return 0;
}
