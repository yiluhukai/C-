/*
 *	
 *	二级指针遍历字符串数组
 *
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
	char* str[] = {"巴西","意大利","法国","德国","英国"};
	char **p =str;
	for(int i=0;i<5;i++){
		printf("%s\n",*(p+i));
	}
	srand(time(0));
	int j=rand()%5;
	printf("我预测的冠军是%s\n",*(p+j));
	return 0;
}
