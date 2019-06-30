/*
 *
 *	stack 测试： 
 *	shell: gcc -D Max = 3 stack_main.c stack.c 
 *
 */

#include <stdio.h>
#include "stack.h"

int main(){
	// 初始化一个栈
	Stack stack;
	int a = 0;
	//初化栈
	initStack(&stack);
	//判断栈为空吗
	bool isEmpty = stackIsEmpty(&stack);
	printf("栈为空吗%d\n",isEmpty);
	bool isFull = stackIsFull(&stack);
	printf("栈满了吗%d\n",isFull);

	int size = stackSize(&stack);
	printf("栈的长度为%d\n",size);
	//进栈
	stackPush(&stack,10);
	stackPush(&stack,20);
	stackPush(&stack,30);
	//获取栈顶的元素
	stackTop(&stack,&a);
	printf("栈顶的元素为%d\n",a);
	//出栈
	stackPop(&stack,&a);
	printf("栈顶元素为%d\n",a);
	stackPop(&stack,&a);
	printf("栈顶元素为%d\n",a);
	stackPop(&stack,&a);
	printf("栈顶元素为%d\n",a);
	isFull = stackIsFull(&stack);
	printf("栈满了吗%d\n",isFull);
	size = stackSize(&stack);
	printf("栈的长度为%d\n",size);
	clearStack(&stack);
	return 0;
}

