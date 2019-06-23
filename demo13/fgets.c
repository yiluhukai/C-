/*
 *
 *	fgets()
 *
 */


#include <stdio.h>
#include <stdlib.h>
int main(){
	char * str = (char *)malloc(sizeof(int)*20);
	if(!str){
	
		printf("分配内存空间失败");		
		return -1;
	}
	
	//从标准输入中读取数据并保存到字符串中
	fgets(str,10,stdin);
	printf("%s\n",str);
	free(str);
	str=NULL;
	return 0;
}
