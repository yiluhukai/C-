//实现一颗二叉树
#include <stdlib.h>
#include "tree_02.h"	

//初始化二叉树
//为什么要穿指针呢 ？因为结构体是值传递，只传入结构体的化，修改结构体中指针的指向不会影响原来的结构体
void tree_init(tree * T){
	T->p_node = NULL;
}

void tree_clear(tree * T){
	//清理的顺序很重要，先清除左右子树，再释放这个结点；否则两个指向左右的子树会丢失 
	if(!T->p_node){
		//当时叶子结点的时候,就停止遍历
		return;
	}
	tree_clear(&(T->p_node->left));
        tree_clear(&(T->p_node->right));
	free(T->p_node);
	T->p_node = NULL;		
}
//查找要插入节点的位置
//假设当前的树是一颗有序的二叉树，比当前节点打的插入到左子树上，比当前的结点小的插入到右子树上。
//val是要插入的值
tree * search(const tree* T,int val){
	//当前树的是一颗空树，则在当前位置插入
	if(T->p_node==NULL)
	{
		//T是const类型的，需要强制转换，否则会有警告
		return (tree *) T;
	}
	//当树不是一颗空树的时候
	if(T->p_node->data == val){
		//当前结点的值等于val
		return (tree *)T;
	}else if(T->p_node->data>val){
		//左子树上查找
		return search(&(T->p_node->left),val);
	}else if(T->p_node->data<val){
		//右子树上插入
		return search(&(T->p_node->right),val);
	}
}
//在有序二叉树中插入结点

int tree_insert(tree* T,int val){
	//先查找到需要插入的位置
	tree* tree_temp = search(T,val);
	//检测当前位置是否有值了
	if(tree_temp->p_node){
		return 0;
	}else{
		//当前结点不存在
		node * new_node =(node*)malloc(sizeof(node));
		if(!new_node){
			//分配失败
			return 0;
		}
		//分配成功
		new_node->data = val;
		new_node->left.p_node = NULL;
		new_node->right.p_node = NULL;
		tree_temp->p_node = new_node;
		return 1;
	}
}
//中序遍历当前二叉树
//因为当前的二叉树是有序二叉树，所以中序遍历就是按照从小到大的顺序来进行的 
void tree_miter(const tree * T,void (*p_func)(int)){
	if(T->p_node==NULL){
		return;
	}
	//遍历左子树
	tree_miter(&(T->p_node->left),p_func);
	//执行输出函数打印当前结点的值
	p_func(T->p_node->data);
	//遍历右子树
	tree_miter(&(T->p_node->right),p_func);
		
}



