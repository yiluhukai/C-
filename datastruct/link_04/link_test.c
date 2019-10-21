#include <stdio.h>
#include "double_link.h"
int main(){
	//初始化一个链表
	link lnk ={0};
	link_init(&lnk);
 	int size = link_count(&lnk);
	printf("link size = %d\n",size);
	//插入新的几点
	link_head_add(&lnk,10);
	link_tail_add(&lnk,20);
	link_insert(&lnk,30);
	link_insert(&lnk,50);
	int data =0;
	link_head_get(&lnk,&data);
	printf("头结点的值为%的=%d\n",data);
	link_tail_get(&lnk,&data);
	printf("尾结点的值为%的=%d\n",data);
	for(int i= 0;i<4;i++){
		link_get(&lnk,&data,i);
		printf("编号=%d,data = %d\n",i,data);
	}
 	size = link_count(&lnk);
	printf("link size = %d\n",size);
//	link_clear(&lnk);
 //	size = link_count(&lnk);
	printf("link size = %d\n",size);
	//使用遍历打印链表
	link_start(&lnk);
	int status =0;
	while(1){
		status = link_next(&lnk,&data);
		if(status == 0){
			//表示已经不在遍历过程中或者遍历结束了
			break;
		}
		printf("data = %d\n",data);
	}
	return 0;
}
