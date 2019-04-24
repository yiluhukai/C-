/*
 *输入一个整形，输出这个数中包含的2进制的1的个数。
 */

#include <stdio.h>

int main(){
	int num = 0, sum = 0;
	scanf("%x",&num);
	for(int j = 31; j>=0; j--)
	{
		if(num & 0x1<<j){
			printf("1");
			sum++;
		}else{
			printf("0");
		}
	}
	printf("\n%d\n",sum);
	return 0;
}
