/*
 *  类型不一样的赋值 
 *  1.int = char
 *  2.char= int 
 *  3.int= float  
 */

#include <stdio.h>


int main()
{
	int i=0xFFFFFFFF;
	char c=0x1;
        printf("i=%x\n",i);
	printf("c=%x\n",c);
	//将c复制给i;
	i=c;
	printf("i=%x\n",i);
	printf("c=%x\n",c);	
	return 0;
}
