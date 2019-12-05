#include <stdio.h>
/*
 *
 *
 *
 *	冒泡排序:采用先确定位置然后找数字的方法（位置只能在最前面或者最后面），确定位置后通过不断
 *	交换位置的方法将数字调整到合适的位置
 *
 */
//p_val代表待排序的数组，size代表的数字的个数
void bubble_sort(int *p_val,int size){
	// 合适的位置设置在最后面
	int temp = 0;
	for(int j = size-1;j>0;j--){
		// 相邻的两个数交换位置
		for(int i=0;i<=j-1;i++){
		  if(*(p_val+i)>*(p_val+i+1)){
		  	// 交换位置
			temp = *(p_val+i);
			*(p_val+i) = *(p_val+i+1);
			*(p_val+i+1) =temp;	
		  }
		}
	}
}
/*
 *
 *	选择排序：采用的还是先确定位置后找数字的方法（位置只能在最前面或者最后面）
 *	通过不断的交换选择位置和其他位置的方式将合适的数字放到选择的位置上。
 *
 */
void choice_sort(int* p_val,int size){
	int temp = 0;
	// 位置选择到最后
	for(int num=size-1;num>0;num--){
		for(int other = 0; other<=num-1;other++){
			if(*(p_val+other) > *(p_val+num)){
				temp =*(p_val+other);
				*(p_val+other) = *(p_val+num);
				*(p_val+num) = temp;
			}
		}
	}
}
int main(){
	int arr[] = {60,30,10,80,50,100,20};
	int size =sizeof(arr)/sizeof(arr[0]);
	// bubble_sort(arr,size);
	choice_sort(arr,size);
	for(int i=0;i<=size-1;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
	return 0;
}
