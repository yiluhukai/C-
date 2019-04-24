/*
 *
 *	rand()用来生成随机数，不设置种子每次运行产生的随机数都是一样的
 *	srand()用来设置种子，相同的种子产生的随机数也是一样的，所以使用时间戳来最为种子
 *	产生7个随机数
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
	//使用当前的时间做为种子
	srand(time(0));
	for(int i = 0;i < 7;i++ ){
		printf("%d\n",rand());
	}
	return 0;
}
