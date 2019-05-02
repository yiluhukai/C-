/*
 *
 *	使用goto语句和if语句实现循环
 *
 */

#include <stdio.h>

int main(){
	int i=0;
label:
	if(i < 5){
		printf("hello wolrd!\n");
		i++;
		goto label;
	}else{
	
		goto over;
	}
over:
	return 0;
}
