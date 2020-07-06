/*
 *
 *	注册遗言函数
 *
 *
 */


#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
void destory(void){

	printf("I have died ...\n");
}

void init(void){
	printf("initing ...\n");
}
int main(){

	//注册遗言函数	
	atexit(destory);
	atexit(destory);
	atexit(destory);
	// 最后注册的先执行
	atexit(init);
	// fork子进程
	pid_t pid = fork();
	if(pid == -1){
		perror("fork");
		return -1;
	}
	if(pid == 0){
		printf("I am child thread!\n");		
	}else{
		getchar();
		printf("I am parent thread\n");
	}
	return 0;
}
