/*
 *
 *	检测机器一秒钟可以输出多少次
 *
 */

#include <unistd.h>
#include <stdio.h>
int main(){
	//  1秒后向当前进程发送SIGALRM signal，然后进程处理会终止当前进程。
	alarm(1);
	int i= 1;
	while(i>0){
		printf("%d\n",i++);
	}
	return 0;
}
