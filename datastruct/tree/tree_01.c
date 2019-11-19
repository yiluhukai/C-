//定义结点的结构体


typedef  struct node {
	int data;
	struct node * left_tree;
       	struct node * right_tree;
}tree_node;


void init_tree(tree_node* tree){
	tree->NULL;
}

//清空一棵树


void clear_tree(tree_node * tree){
	if(tree == NULL){
		return;
	}
	clear_tree(tree->left_tree);
	clear_tree(tree->right_tree);
	free(tree);
	tree =NULL:
}
