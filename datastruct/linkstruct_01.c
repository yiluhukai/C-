/*
 *
 *	单项链式数据结构
 *
 */

#include <stdio.h>
typedef struct node{
	int num;
	struct node * next;
}Node;

void printfNode(Node* n){
    while(n){
		printf("%d\n",n->num);
		n =n->next;
	}
}
int main(){
	//num =10;next=NULL
	Node num1 = {10};
	Node num2 = {20};
	Node num3 = {30};
    num1.next =&num2;
	num2.next =&num3;
	printfNode(&num1);
	return 0;
}
