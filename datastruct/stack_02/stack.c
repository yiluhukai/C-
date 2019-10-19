/*
 *
 *	栈
 *
 */
#include "stack.h" 


// 初始化一个栈

void initStack(Stack* stack){
	//只需要将栈里的元素个数设置为0个即可；即表明了栈中没有可用的元素
	stack->size = 0;
}
//清空一个栈
void clearStack(Stack* stack){

	stack->size = 0; 

}
//判断栈里面是否满了
bool stackIsFull(const Stack* stack ){
	if(stack->size >= Max){
		return true;
	}else{
		return false;
	}
}

//计算栈中元素的个数

int stackSize(const Stack* stack){

	return stack->size;
}
// 判断栈是否为空

bool stackIsEmpty(const Stack * stack){
	if(stack->size == 0){
		return true;
	}
	return false;
} 
// 向栈里面加入数据

bool stackPush(Stack * stack,int val){
	//先判断栈是否满了
	if(stack->size >= Max){
		return false;
	}else{
		stack->stack[stack->size] = val;
		stack->size++;
		return true;
	}
} 
// 从栈里取数据(并删除当前的数字)
//val用来保存获取到的数据
bool stackPop(Stack* stack,int *val){	
	//先判断栈里面是否有数字
	if(stack->size == 0){
		return false;
	}else{
		//返回栈顶的元素
		*val = stack->stack[stack->size-1];
		//出栈
		stack->size--;
		return true;
	}
}
//获取栈顶的元素，但是不会删除栈顶元素
bool stackTop(const Stack * stack,int *val){
	//判断栈是否为空
	if(!stack->size){
		return false;
	}
	*val = stack->stack[stack->size-1];
	return true;
}
