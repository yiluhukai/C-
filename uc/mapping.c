/*
	mmap(2) 将物理地址映射到进程的虚拟地址
*/

#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
int main(void){
	int  prot = PROT_READ|PROT_WRITE;
	int  flag =MAP_PRIVATE|MAP_ANON;
	int len =1024;
	void *mp = mmap(NULL,len,prot,flag,-1,0);	
	if(mp == MAP_FAILED){
		perror("error:");
		return -1;
	}
	// 映射成功
	strcpy((char *)mp,"hello world!");
	printf("%s",(char *)mp);
	//  取消映射
	munmap(mp,len);
	return 0;
}
