/*
 *		鸡兔同笼问题
 *		头40 ，脚100
 */


#include<stdio.h>
int main()
{
	for(int i=0;i<=40;i++){
		for(int j=0;j<=40;j++){
			if((2*i +  4*j == 100) && (i + j == 40)){
			
				printf("鸡=%d,兔子=%d",i,j);
			}
		}
	}
	return 0;
}
