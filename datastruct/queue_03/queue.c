/*
 *
 *	线行结构的队列
 *	
 */
#include "queue.h"
//初始化队列:指向0的原因：
//1.防止数组的下标溢出。
//2.从0开始不会造成空间浪费

void queue_init(Queue * p_queue){
	p_queue->head = 0;
	p_queue->tail = 0;
}

//销毁队列

void queue_clear(Queue * p_queue){

	p_queue->head =0;
	p_queue->tail =0;
}

//判断队列是否为空
bool queue_empty(const Queue* p_queue){
	if(p_queue->head == p_queue->tail){
		return true;
	}
	return false;
}
// 判断队列是否满了

bool queue_full(const Queue* p_queue){
	if(p_queue->tail >= Max){
		return true;
	}

	return false;
	
}
//返回队列的长度

int queue_size(const Queue* p_queue){
	return p_queue->tail - p_queue->head;
}

// 向队列中加入数字

bool queue_push(Queue* p_queue,int val){
	//先判断这个队列是否满了
	if(p_queue->tail>=Max)
		return false;
	p_queue->buf[p_queue->tail] = val;
	p_queue->tail++;
	return true;
}

//从队列中取出数字，同时删除队列中的这个元素

bool queue_pop(Queue* p_queue,int *val){
	//先判断这个队列是否为空
	if(p_queue->head == p_queue->tail)
		return false;
	*val = p_queue->buf[p_queue->head];
	p_queue->head++;
	return true;
}
//从队列中取出元素，同时不会删除队列中的元素

bool queue_front(Queue* p_queue,int *val){
	// 判断队列是否为空
	if(p_queue->tail == p_queue->head)
		return false;
	*val = p_queue->buf[p_queue->head];
	return true;
}
