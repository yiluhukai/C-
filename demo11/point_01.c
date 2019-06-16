/*
 *
 *	二级指针和作用
 *
 */

#include <stdio.h>
// 修改一级指针的指向
void fixpoint(int ** p){
	*p = NULL;
}

int main(){
	int a =10;
	int *p = &a;
	int **pa =&p;
	printf("p=%p",p);
	fixpoint(pa);
	printf("p=%p",p);
#if 0
	printf("a=%d\n",**pa);
#endif
	return 0;
}
