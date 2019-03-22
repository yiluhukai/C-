/*
 *
 * 位运算符
 *
 */
#include <stdio.h>
int main(){

	//&
	//0000 0011
	//0000 0001
	//0000 0001
	printf("0x03&0x01=0x%x\n",0x03&0x01);
	//>>
	char c=0x81;
	//1000 0001
	//>>3 1111 0000  
	//f0
	printf("0x81>>3=%x\n",c=c>>3);
	unsigned char uc = 0x81;
	//1000 0001
	//>>3 0001 0000
	printf("0x81>>3=%x\n",uc=uc>>3);
	return 0;
}
