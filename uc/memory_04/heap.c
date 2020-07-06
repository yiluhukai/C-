#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main(void){
	int* mp =(int *) malloc(sizeof(int)*10);
	//在堆上分配内存空间
	printf("PID = %d\n",getpid());
	//打印内存地址
	printf("mp point address =%p\n",mp);

	free(mp);
	printf("map oint address =%p\n",mp);
	getchar();
	return 0;
}
