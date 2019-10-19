/*
 *
 * 带头节点和尾节点的链表
 * head --> first ---> second .... tail.
 */
#include <stdio.h>
typedef struct node{
	int num;
	struct node * next;

}Node;
int main(){
	Node num1 ={10};Node num2 = {20}; Node num3 = {30};
	Node head= {0};Node tail ={0};
    //连接所有的节点
	head.next =&num1;
	num1.next =&num2;
	num2.next =&num3;
	num3.next = &tail;
    //遍历打印所有有效节点的值；
	//
	for(Node* n_node = &head;n_node !=&tail;n_node =n_node->next){
	
	    Node* first = n_node;
		Node* mid  =first->next;
		Node* last = mid->next;
		if(mid!=&tail){
			printf("%d\n",mid->num);
		}
	}
	return 0;
}	
