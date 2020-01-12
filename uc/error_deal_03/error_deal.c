#include <stdio.h>
#include <errno.h>
#include <string.h>
// 通过errno来查找错误的原因
//  gcc error_deal.c  
//  ./a.out hello
//  可以看到errno和打印的错误信息
int main(int args,char * argv[]){
	FILE * f = fopen(argv[1],"r");
	if(f== NULL){

		printf("open file failed ...\n");
	//	printf("errno=%d\n",errno);
	//	printf("error message:%s\n",strerror(errno));
		perror("fopen");
		return -1;
	}
	printf("open file success...\n");
	fclose(f);
	return 0;
}
