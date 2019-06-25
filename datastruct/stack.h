#ifndef __STACK__H__
#define __STACK__H__ 

// 使用枚举自定义bool类型
typedef enum{
	false,
	true
}bool;

//
//  定义一个栈的结构体；采用顺序结构

typedef struct{
	int stack[Max];
	int size; //指定栈里面的元素的个数；同时可以用来计算栈中的最后一个元素
}Stack;

// 初始化一个栈

void initStack(Stack* stack);
//清空一个栈
void clearStack(Stack* stack);

//判断栈里面是否满了
bool stackIsFull(const Stack* stack );
//计算栈中元素的个数

int stackSize(const Stack* stack);

// 判断栈是否为空

bool stackIsEmpty(const Stack * stack);
// 向栈里面加入数据

bool stackPush(Stack * stack,int val);
	//先判断栈是否满了
// 从栈里取数据(并删除当前的数字)
//val用来保存获取到的数据
bool stackPop(Stack* stack,int *val);	
//获取栈顶的元素，但是不会删除栈顶元素
bool stackTop(const Stack * stack,int *val);

#endif
