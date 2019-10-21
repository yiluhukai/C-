/*
 *	实现一个带有头结点和尾节点的链表
 *
 *	
 */

// 定义链表中的节点的结构体


#ifndef __LINK_H__
#define __LINK_H__ 

typedef struct node{
	int data;
	struct node* next;
}node;


//定义一个代表链表的机构体

typedef struct{
	node head;
	node tail;
}link;



// 初始化链表

void link_init(link* p_link);


// 清空链表


void link_clear(link* p_link);


// 计算链表中元素的个数

int link_count(const link* p_link);

//头插入
int link_head_add(link* p_link,int val);

int link_tail_add(link * p_link,int val);

//按照从小到大的顺序插入

int link_insert(link* p_link,int val);
//从链表的头部删除一个节点,成功返回1，失败返回0

int link_head_delete(link *p_link);
//从尾部删除节点

int link_tail_delete(link * p_link);
//删除任意一个值为val的节点

int link_delete(link* p_link,int val);
// 获取链表的头结点

int link_head_get(const link* p_link,int* val);
// 获取链表尾结点的值

int link_tail_get(const link* p_link,int* val);

// 获取链表中指定编号的值，标号从零开始


int link_get(const link* p_link,int * val,int sn);
#endif
