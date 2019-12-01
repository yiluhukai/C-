#include <stdio.h>
#include "tree_02.h"
void show(int val){

	printf("%d\t",val);
}

int main(){
	tree T = {0};
        tree_init(&T);
	tree_insert(&T,10);
	tree_insert(&T,10);
	tree_insert(&T,6);
	tree_insert(&T,-1);
	tree_insert(&T,-12);
	tree_insert(&T,1);
	tree_insert(&T,20);
	tree_insert(&T,0);
	tree_insert(&T,9);
	tree_insert(&T,11);
	tree_miter(&T,show);
	printf("\n");
	tree_remove(&T,6);
	tree_remove(&T,20);
	tree_miter(&T,show);
	printf("\n");
	return 0;	

}
