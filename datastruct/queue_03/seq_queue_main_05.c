/*
 *
 *	循环队列的测试
 *	
 */

#include <stdio.h>
#include "seq_queue.h"
#include <time.h>
#include <stdlib.h>
int main(){
	srand(time(0));
	Seq_Queue queue={0};
	queue_init(&queue);
	//打印队列的长度
	printf("队列的长度：%d\n",queue_size(&queue));
	printf("队列是否为空：%d\n",queue_empty(&queue));
	printf("队列是否满了：%d\n",queue_full(&queue));
	//向队列中加入四个元素
	int rand_num = rand()%10;
	queue_push(&queue,rand_num);
	rand_num = rand()%10;
	queue_push(&queue,rand_num);
	rand_num = rand()%10;
	queue_push(&queue,rand_num);
	rand_num = rand()%10;
	queue_push(&queue,rand_num);
	printf("队列的长度：%d\n",queue_size(&queue));
	printf("队列是否为空：%d\n",queue_empty(&queue));
	printf("队列是否满了：%d\n",queue_full(&queue));
	//打印队列中最后一个元素
	int last_num = 0;
       	queue_front(&queue,&last_num);
	printf("队列中最后的元素%d\n",last_num);
	//取出队列中的最后一个元素
	queue_pop(&queue,&last_num);
	printf("队列中最后的元素%d\n",last_num);
	//打印队列的长度
	printf("队列的长度：%d\n",queue_size(&queue));
	printf("队列是否为空：%d\n",queue_empty(&queue));
	printf("队列是否满了：%d\n",queue_full(&queue));
	queue_clear(&queue);
	//打印队列的长度
	printf("队列的长度：%d\n",queue_size(&queue));
	printf("队列是否为空：%d\n",queue_empty(&queue));
	printf("队列是否满了：%d\n",queue_full(&queue));

	return 0;
}
