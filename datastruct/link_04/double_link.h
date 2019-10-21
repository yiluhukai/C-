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
	struct node* prev;
	struct node* next;
}node;


//定义一个代表链表的机构体

typedef struct{
	node head;
	node tail;
	//节省遍历的时间，当指针不指向NULL的时候，表示在遍历过程中。通过link_start进入遍历，link_next(）函数获取遍历的下一个结点的值
	//cur指针表示上一次遍历的位置
	node * cur;
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
//开始进入遍历过程
void link_start(link* p_link);
//获取遍历过程中下一位置的值
int link_next(link* p_link,int * val);
#endif
