/*
 *
 * printf()中要输出的内容会保存在缓存区,满足以下条件的时候才会输出;
 *   1. 有\n换行。
 *   2. 缓存区满了
 *   3. 程序结束
 *   4. fflush(stdout) 输出缓存区被清空
 *	
 *	
 *
 */
#include <stdio.h>
#include <unistd.h>
int main(){
 	for(int i;i<6;i++){
		printf("   %d",i);
		//不清理缓存区会在程序结束时将缓存区的内容推送到屏幕上；
		fflush(stdout);
		sleep(1);
	}
 	return 0;
}
