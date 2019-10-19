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

//按照从小到大的顺序插入

int link_insert(link* p_link,int val){
	//动态分配节点
	node * n_node =(node*) malloc(sizeof(node));
	if(!n_node){
		return 0;
	}
	//找到插入的位置
	n_node->data = val;
	n_node->next= NULL;
	for(node * p_temp = &(p_link->head);p_temp!=&(p_link->tail);p_temp=p_temp->next){
		node* p_first = p_temp;
		node* p_mid =p_first->next;
		node* p_last = p_mid->next;
		//先检查当前链表是否为空或者所有的值都小于val,当不满足当前条件，在检测怕p_mid中的值是否大于val
		if(p_mid == &(p_link->tail) || p_mid->data>val){
			p_first->next =n_node;
			n_node->next = p_mid;
			break;
		}
	}
	return 1;
}
//从链表的头部删除一个节点,成功返回1，失败返回0

int link_head_delete(link *p_link){
	//分配三个几点
	node * p_first=NULL,*p_mid=NULL,*p_last=NULL;

	p_first =&(p_link->head);
	p_mid = p_first->next;
	p_last = p_mid->next;
	//代表有数据节点
	if(p_mid !=&(p_link->head)){
		p_first->next = p_last;
		free(p_mid);
		p_mid=NULL;
		return 1;
		//删除成功
	}
	return 0;
}
//从尾部删除节点

int link_tail_delete(link * p_link){
	//找到最后一个数据节点

	for( node* p_temp=&(p_link->head);p_temp !=&(p_link->tail); p_temp = p_temp->next){
		node *p_first = p_temp;
		node *p_mid = p_first->next;
		node *p_last = p_mid->next;
		if(p_last == &(p_link->tail)){
			p_first->next = p_last;
			free(p_mid);
			p_mid = NULL;
			return 1;
		} 
	}
	//执行完上面没有返回，说明是一个空的链表；
	return 0;
}
//删除任意一个值为val的节点

int link_delete(link* p_link,int val){
	//遍历链表查找要删除的结点
	node* p_temp=NULL;
	for(p_temp=&(p_link->head);p_temp!=&(p_link->tail);p_temp=p_temp->next){
		node *p_first = NULL, *p_mid=NULL,*p_last=NULL;
		p_first = p_temp;
		p_mid=p_first->next;
		p_last =p_mid->next;
		if(p_mid!=&(p_link->tail) && p_mid->data ==val){
			p_first->next = p_last;
			free(p_mid);
			p_mid=NULL;
			return 1;
		}else{
			//没有有效的数据结点或者没找到值等于val的结点
			return 0;
		}
	}
}
// 获取链表的头结点

int link_head_get(const link* p_link,int* val){
	const node * p_first=NULL,*p_mid =NULL,*p_last=NULL;
	p_first=&(p_link->head);
	p_mid = p_first->next;
	p_last =p_mid->next;
	if(p_mid!=&(p_link->tail)){
		//链表存在有效结点
		*val = p_mid->data;
		return 1;
	}else{
		//链表为空
		return 0;
	}
}
// 获取链表尾结点的值

int link_tail_get(const link* p_link,int* val){
	//表里链表去查找最后一个结点
	const node * p_temp = NULL;
	for(p_temp = &(p_link->head);p_temp!=&(p_link->tail);p_temp=p_temp->next){
		const	node* p_first = p_temp;
		const node* p_mid = p_first->next;
		const node* p_last = p_mid->next;
		if(p_last == &(p_link->tail)){
			*val = p_mid->data;
			return 1;
		}
	}
	return 0;

}

// 获取链表中指定编号的值，标号从零开始


int link_get(const link* p_link,int * val,int sn){
	int ctn = 0;
	for(const node* p_temp;p_temp!=&(p_link->tail);p_temp=p_temp->next){
		const node* p_first = p_temp;
		const node* p_mid = p_first->next;
		const node* p_last = p_mid->next;
		if(p_mid!=&(p_link->tail) && sn == ctn){
			*val = p_mid->data;
			return 1;
		}
	}
	return 0;
	
}
