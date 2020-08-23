/*
 *
 *	使用mutex和条件变量实现生产者和消费者模型
 *
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//  生产者和消费者可能同时访问head

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

//扩展作用域
struct node;

typedef struct node node_t;
typedef node_t * list_t;

struct node{
	int data;
	node_t* next;    
};

list_t head = NULL;

void * produce(void * arg){
	while(1){
		// 
		sleep(rand()%5+1);
	 	list_t new =(list_t)malloc(sizeof(node_t));
		new->data=(rand()%1000)+1;
		printf("produce:%d\n",new->data);
		new->next=NULL;
		// 将节点放入连表中
		// 加锁
		pthread_mutex_lock(&mutex);
		new->next=head;
		head=new;
		pthread_mutex_unlock(&mutex);
		//通知等待的消费者去使用
		pthread_cond_signal(&cond);
	}
	return NULL;
}

void * consume(void * args){
	while(1){
		sleep((rand()%5)+1);
		pthread_mutex_lock(&mutex);
		if(head == NULL){
			// 等待生产者区生产 // wait会先将解锁等待，返回之前重新获得锁
			pthread_cond_wait(&cond,&mutex);

		}
		//  从链表的头部取出节点
		list_t temp =  head;
		head=head->next;
		pthread_mutex_unlock(&mutex);
		printf("thread =%s consume=%d\n",(char *)args,temp->data);
		free(temp);
		temp=NULL;
		
	}
	return NULL;
}


int main(){
	//  设置随机数种子
	srand(time(NULL));
	// 创建两个线程，一个是生产者，两个是消费者
	pthread_t th1,th2,th3;
	pthread_create(&th1,NULL,produce,NULL);
	pthread_create(&th2,NULL,consume,"th1");
	pthread_create(&th3,NULL,consume,"th2");
	//  等待两个线程的退出
	
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	pthread_join(th3,NULL);
	// 销毁mutex
	pthread_mutex_destroy(&mutex);
	//  销毁条件变量
	pthread_cond_destroy(&cond);
	return 0;
}
