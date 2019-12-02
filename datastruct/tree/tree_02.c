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

// 删除树中的某个结点，当该值在树中不存在的时候返回0
//

int tree_remove(tree * T,int val){
	//先查找要删除的结点的位置
	tree* node_temp = search(T,val);
	// 保存要删除的结点的指针
	node* remove_node = node_temp->p_node; 
	if(!remove_node){
		return 0;
	}
	//代表要删除的结点已经存在,会有四种情况“
	// 1.要删除的结点没有左子树
	if(!remove_node->left.p_node &&  !remove_node->right.p_node){
		//直接删除并释放当前指针
		node_temp->p_node =NULL;
	}else if(!remove_node->right.p_node){
		//只有左子树
		node_temp->p_node = remove_node->left.p_node;
	}else if(!remove_node->left.p_node){
		// 只有右子树
		node_temp->p_node = remove_node->right.p_node;
	}else{
		// 左子树和右子树同时存在
		// 这种情况比较复杂，需要将当前要删除结点的左右子树合成一棵树
		// 合成方法有两种：1.将要删除结点的左子树的最右边的结点的右指针指向左子树的跟结点
		// 2. 将要删除结点的右子树的最左边的结点左子树指向左子树。 
		//  原理：当前结点的左子树的最大结点是最左的结点，二子树的结点是大于删除结点的值的 。
		tree * p_temp1 = search(&(remove_node->left),remove_node->right.p_node->data);
		p_temp1->p_node =remove_node->right.p_node;
		node_temp->p_node = remove_node->left.p_node;
	}
	// 最终释放要删除的结点
	free(remove_node);
	return 1;
}
//获取树的高度
// 因为树的左子树和右子树也是一棵树，所以可以使用递归来实现
int tree_height(const tree* T){
	if(!T->p_node){
		return 0;
	}
	//树有结点
	int left_height = tree_height(&(T->p_node->left));
	int right_height = tree_height(&(T->p_node->right));
	return (left_height>right_height?left_height:right_height)+1;
}

// 获取树的结点的个数
//
int tree_count(const tree* T){
	if(!T->p_node){
		return 0;
	}
	//结点存在
	int left_count = tree_count( &(T->p_node->left));
	int right_count =  tree_count(&(T->p_node->right));
	return left_count + right_count + 1;
}
