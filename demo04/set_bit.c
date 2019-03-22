/*
 *把指定比特位变为0或1
 *
 */
#include <stdio.h>
int main(){
	//  0100 0001 ，将比特6位变为0
	//& 1011 1111 
	int i = 0x41;
	//int g =(i&0xffffffaf);
	i=i & ~(1<<6);
	printf("i=0x%x\n",i);
	// 将比特6位变为1
	i=i | (1<<6);
	printf("i=0x%x\n",i);
	return 0;
}
