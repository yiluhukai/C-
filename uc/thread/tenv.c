/*
 *
 *
 *	通过全局变量获取进程的环境便利
 *
 *
 *
 */
#include <stdio.h>
#include <unistd.h>
extern char **environ; 
int main(){
	int i;
	for(i=0;environ[i]!=NULL;i++){
		printf("%s\n",environ[i]);
	}		
	return 0;
}
