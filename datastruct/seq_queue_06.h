/*
 *
 *	循环队列的另一种实现方式
 *       
	当头结点和尾节点相等是表示队列为空，当尾节点的下一个节点为头结点是，代表队列满了。
 */
#ifndef SEQ_QUEUE_06_H
#define SEQ_QUEUE_06_H
typedef struct{
	int buf[Max];
	int head; 
	int tail;
}Queue;

typedef enum{
	false,
	true	
}bool;

// 初始队列


void queue_init (Queue *  seq);

// 清空队列

void queue_clear(Queue * seq);
//返回队列的长度

int queue_size(const Queue* seq);

//判断队列是否为空
bool queue_empty(const Queue* seq);
//判断队列是否满了
bool queue_full(const Queue* seq);
//从队列中取出一个元素同时删除这个元素

bool queue_pop( Queue* seq,int* val);

//返回队列头部的数据，但是不会删除队列中元素

bool queue_front(const Queue* seq,int * val);

// 向队列中插入一个元素

bool queue_push(Queue* seq,int val);
#endif
