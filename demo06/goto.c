/*
 *
 *	随机生7个32以内的正数，并且不能出现重复
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int arr[7];
	srand(time(0));
start:		
	//生成一组随机数
	for(int i = 0;i < 7; i ++){
		arr[i] = rand()%32;
	}
	//打印这组随机数
	for(int i=0;i < 7 ; i ++){
		printf("%d\n",arr[i]);
	}
	//检验数组中是否有重复的数
	for(int i =0 ; i< 7; i++){
		for(int j=i+1;j<7;j++){
			if(arr[i] == arr[j]){
				printf("数组中的数字有重复\n");
				goto start;
			}
		}
	}	
	return 0;
}
