/*
 *	时间相关的函数
 *
 */

#include <stdio.h>
#include <time.h>


int main(){
	long int sec = 0;
	time(&sec);
	printf("%ld\n",sec);
	char * p =NULL;
	p = ctime(&sec);
	printf("%s\n",p);
	struct tm *pi =NULL;
	pi = localtime(&sec);
	printf("%d年%d月%d日\n",pi->tm_yday+1900,pi->tm_mon+1,pi->tm_mday);
	p = asctime(pi);
	printf("%s\n",p);
	return 0;
}
