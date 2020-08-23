/*
 *
 *	利用信号量实现生产者和消费者模型
 *
 */

#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
// 使用环形队列区保存数据

#define MAX_QUEUE 7


typedef int  queue_t[MAX_QUEUE];
queue_t que; 

//  c代表环状队列中可以消费的数量，p代表环状队列中可以生产的数量
sem_t c,p;



void * produce(void * arg){
	int rear = 0;
	while(1){

		sleep(rand()%5+1);
		//  先判断是否可以生产
		// p--
		sem_wait(&p);
		que[rear]=(rand()%1000)+1;
		printf("produce:%d\n",que[rear]);
		rear= (rear+1)%MAX_QUEUE;
		// 可以消费数+1
		sem_post(&c);
	}
	return NULL;
}

void * consume(void * args){
	//  队列开始位置的下标
	int front =0;
	while(1){
		sleep((rand()%5)+1);
		//  先判断可以消费不
		//  c--
		sem_wait(&c);

		int temp = que[front];
		front=(front+1)%MAX_QUEUE;

		printf("thread=%s consume:%d\n",(char *)args,temp);
		//  可生产数+1
		sem_post(&p);

	}
	return NULL;
}


int main(){
	//  设置随机数种子
	srand(time(NULL));

	// 对两个信号两进程初始化
	sem_init(&c,0,0);
	sem_init(&p,0,MAX_QUEUE);
	// 创建两个线程，一个是生产者，一个是消费者
	pthread_t th1,th2;
	pthread_create(&th1,NULL,produce,NULL);
	pthread_create(&th2,NULL,consume,"th1");
	//  等待两个线程的退出

	pthread_join(th1,NULL);
	pthread_join(th2,NULL);

	// 销毁mutex
	sem_destroy(&p);
	//  销毁条件变量
	sem_destroy(&c);
	return 0;
}

