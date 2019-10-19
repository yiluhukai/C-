/*
 *
 *	循环队列的另一种实现方式
 *       
	当头结点和尾节点相等是表示队列为空，当尾节点的下一个节点为头结点是，代表队列满了。
 */


// 初始队列
#include "seq_queue_06.h"

void queue_init (Queue *  seq){
	seq->head =0;
	seq->tail=0;	
}


// 清空队列

void queue_clear(Queue * seq){
	seq->head = 0;
	seq->tail =0;
}

//返回队列的长度

int queue_size(const Queue* seq){
	return (seq->tail-seq->head+Max)%Max; 
}

//判断队列是否为空
bool queue_empty(const Queue* seq){
	if(seq->head == seq->tail){
		return true;
	}
	return false;
}
//判断队列是否满了
bool queue_full(const Queue* seq){
	if((seq->tail+Max-seq->head)%Max == Max-1){
		return true;
	}
	return false;
}
//从队列中取出一个元素同时删除这个元素

bool queue_pop( Queue* seq,int* val){
	if(seq->head == seq->tail){
		return false;
	}
	*val = seq->buf[seq->head];
	seq->head++;
	seq->head=seq->head%Max;
	return true;
}

//返回队列头部的数据，但是不会删除队列中元素

bool queue_front(const Queue* seq,int * val){
	if(seq->head == seq->tail){
		return false;
	}
	*val = seq->buf[seq->head];
	return true;
}

// 向队列中插入一个元素

bool queue_push(Queue* seq,int val){
	if((seq->tail+Max-seq->tail)%Max ==Max-1){
		return false;
	}
	seq->buf[seq->tail]= val;
	seq->tail++;
	seq->tail%=Max;
	return true;
}
