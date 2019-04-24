/*
 *
 *	输出计算机时间
 */
#include <stdio.h>
#include <time.h>
#include <unistd.h>
int main(){
	for(;;)
	{
		//打印的是1970年到现在的毫秒数
		printf("sec=%lu\n",time(0));
		sleep(1);
	}
	return 0;
} 
