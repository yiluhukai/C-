#include <stdio.h>
#include <stdlib.h>

void destoryed(int status,void * arg){
	printf("status = %d, args =%s\n",status,(char *)arg);
}

int main(void){
	on_exit(destoryed,"wo will died");
	getchar();
	exit(3);
}
