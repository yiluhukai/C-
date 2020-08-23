/*
 *
 *	两个线程访问同一资源
 *
 */
#include <pthread.h>
#include <stdio.h>
int count = 0;
// 初始化一个mutex

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void* handle(void* args){
	int i;
	for(int j=0;j<5000;j++){
		pthread_mutex_lock(&mutex);
		i=count;
		// 在汇编成机器指令是多条指令的 
		i++;
		printf("args=%s,count = %d\n",(char *)args,i);
		count = i;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main(){
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,handle,"thread1");
	pthread_create(&thread2,NULL,handle,"thread2");
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	//printf("count=%d\n",count);
	printf("main thread exit...\n");
	//  销毁一个mutex
	pthread_mutex_destroy(&mutex); 
	return 0;
}
