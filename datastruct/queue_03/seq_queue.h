/*
 *
 *	循环队列
 *
 */
#ifndef __SEQ_QUEUE__H__
#define __SEQ_QUEUE__H__
typedef enum{
	false,true
}bool;

typedef struct {
	int buf[Max];
	int head;//当队列为空或者队列满了的时候和tail指向同一个位置。
	int tail;//可以使用的下一个位置的下标
	int size; //用来区分队列是空还是满了
}Seq_Queue;

//初始化队列 

void queue_init(Seq_Queue* seq);
//销毁队列

void queue_clear(Seq_Queue* seq);
//判断队列是否为空
bool queue_empty(const Seq_Queue* seq);
//判断队列是否满了
bool queue_full(const Seq_Queue* seq);
//返回队列的长度

int queue_size(const Seq_Queue* seq);

// 向队列中加入元素

bool queue_push(Seq_Queue* seq,int val);

//从队列中取出元素，删除这个取出的元素

bool queue_pop(Seq_Queue* seq,int * val);

//返回队列中最后的元素

bool queue_front(const Seq_Queue * seq,int * val);

#endif

