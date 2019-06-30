/*
 *
 *	循环队列
 *
 */

#include "seq_queue.h"
//初始化队列 

void queue_init(Seq_Queue* seq){
	seq->head =0;
	seq->tail =0;
	seq->size =0;
}
//销毁队列

void queue_clear(Seq_Queue* seq){

	seq->head =0;
	seq->tail =0;
	seq->size =0;	
}
//判断队列是否为空
bool queue_empty(const Seq_Queue* seq){
	if(!(seq->size))
		return true;
	return false;
}
//判断队列是否满了
bool queue_full(const Seq_Queue* seq){
	if(seq->size >= Max){
		return true;
	}
	return false;
}
//返回队列的长度

int queue_size(const Seq_Queue* seq){
	return seq->size;
}

// 向队列中加入元素

bool queue_push(Seq_Queue* seq,int val){
	//判断队列是否满了
	if(seq->size == Max){
		return false;
	}
	seq->buf[seq->tail] = val;
	seq->tail++;
	seq->tail %= Max;
	seq->size++;
	return true;
}

//从队列中取出元素，删除这个取出的元素

bool queue_pop(Seq_Queue* seq,int * val){
	if(seq->head == seq->tail){
		return false;
	}
	*val = seq->buf[seq->head];
	seq->head++;
        seq->head %= Max;	
	seq->size--;
	return true;
}

//返回队列中最后的元素

bool queue_front(const Seq_Queue * seq,int * val){
	if(seq->head == seq->tail)
		return false;
	*val = seq->buf[seq->head];
	return true;
}



