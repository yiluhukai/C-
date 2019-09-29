/*
 *	实现一个带有头结点和尾节点的链表
 *
 *	
 */

// 定义链表中的节点的结构体


#include <stdlib.h>
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

void link_init(link* p_link){

	p_link->head.next = &(p_link->tail); 
	p_link->tail.next =  NULL;	
}


// 清空链表


void link_clear(link* p_link){
	//当头结点的指针没有指向尾节点，那么就没有释放完
	while(p_link->head.next!= &p_link->tail){
		node* p_first = &p_link->head;
		node* p_mid =  p_first->next;
		node* p_last = p_mid->next;

		p_first->next = p_last;
		free(p_mid);
		p_mid = NULL;	
	}
}


// 计算链表中元素的个数

int link_count(const link* p_link){
	int count = 0;
	const node* p_node = NULL;
	for(p_node=&(p_link->head);p_node!=&(p_link->tail);p_node=p_node->next){
		const node* p_first = p_node;
		const node* p_mid =p_first->next;
		const node* p_last = p_mid->next;
		if(p_mid!=&(p_link->tail)){
			count++;
		}
	}
	return count;	
}

//头插入
int link_head_add(link* p_link,int val){
	//动态分配一个节点
	node* p_node =(node *)malloc(sizeof(node));
	if(!p_node){
		return 0;
	}	
	//分配成功
	p_node->data=val;
	p_node->next = NULL;	
	node *p_first = &(p_link->head);
	node *p_mid = p_first->next;
	node *p_last = p_mid->next;

	//加节点
	p_node->next=p_mid;
	p_first->next= p_node; 
	return 1;
}

int link_tail_add(link * p_link,int val){
	//动态分配一个节点
	node* p_node =(node *)malloc(sizeof(node));
	if(!p_node){
		return 0;
	}	
	//分配成功
	p_node->data=val;
	p_node->next = NULL;	
	//找出最后一个数据节点，插入数据
	for(node* p_temp=&(p_link->head);p_temp!=&(p_link->tail);p_temp=p_temp->next){
		node *p_first = p_temp;
		node *p_mid = p_first->next;
		node *p_last = p_mid->next;
                if(p_mid == &(p_link->tail)){
			p_first->next = p_node;
			p_node->next= p_mid;
			break;
		
		}
		
	}
	return 1;
}
