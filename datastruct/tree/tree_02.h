// 测试一棵树





#ifndef TREE__02__H

#define TREE__02__H

struct node;

typedef struct {
	struct node* p_node;  
}tree;

typedef struct node{
	int data;
	tree left;
	tree right;	
	
}node;

void tree_init(tree * T);

void tree_clear(tree * T);

//在有序二叉树中插入结点

int tree_insert(tree* T,int val);
// 中序遍历有序树
void tree_miter(const tree * T,void (*p_func)(int));

int tree_remove(tree * T,int val);
#endif
