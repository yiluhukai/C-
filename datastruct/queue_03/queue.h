/*
 *
 *	线行结构的队列
 *	
 */
#ifndef __QUEUE__H__
#define __QUEUE__H__
typedef struct{
	int buf[Max];
	int head;//队列的开始，当队列为空时，和tail相等
	int tail;// 纸箱队列中下一个可以使用的位置
}Queue;

typedef enum {
	false,true
}bool;

//初始化队列:指向0的原因：
//1.防止数组的下标溢出。
//2.从0开始不会造成空间浪费

void queue_init(Queue * p_queue);

//销毁队列

void queue_clear(Queue * p_queue);

//判断队列是否为空
bool queue_empty(const Queue* p_queue);
// 判断队列是否满了

bool queue_full(const Queue* p_queue);
//返回队列的长度

int queue_size(const Queue* p_queue);

// 向队列中加入数字

bool queue_push(Queue* p_queue,int val);

//从队列中取出数字，同时删除队列中的这个元素

bool queue_pop(Queue* p_queue,int *val);
//从队列中取出元素，同时不会删除队列中的元素

bool queue_front(Queue* p_queue,int *val);
#endif
