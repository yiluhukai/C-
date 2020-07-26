/*
 *
 *
 *	获取对应name的环境变量
 *
 *
 */

#include <stdlib.h> 
#include <stdio.h>
int main(){
	// 默认会继承父进程的环境变量
	char *env = getenv("name");
	if(env ==NULL){
		printf("no macth\n");
		return -1;
	}
	printf("name=%s\n",env);
	return 0;
}
