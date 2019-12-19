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
/*
 *
 *	插入排序：采用的是先找数字后确定位置的方法
 *	假设前面一组或后面一组数字是排好序的。把与他们相邻的数组作为选定数字。
 *	每次把选定数字和他前面的相邻数字比较，知道把数字插入到合适的位置。
 *
 *
 */
void insert_sort(int* p_val,int size){
	int temp = 0;
	for(int num = 1;num<=size-1;num++){
		//num是选定数字，num前面的数字是有序数字
		for(int num1 = num-1;num1>=0;num1--){
			if(*(p_val+num1)>*(p_val+num1+1)){
				temp = *(p_val+num1);
				*(p_val+num1) = *(p_val+num1+1);
				*(p_val+num1+1) =temp;		
			}else{
				break;
			}
		}
	}
}
/*
 *
 *	快速排序：采用先找数字再找位置的方法。
 *	在待排序的数字中最前面或者最后面的数字作为选定数字。
 *	将选定数字和其他的数字作对比，将他放到和合适的位置。保证前面的数字比他小，后面的数字比他大
 *	然后对这个数字前面和后面的数字使用快速排序，当待排序的数字个数小于等于1的时候，停止排序。
 *
 */
void quick_sort(int * p_val,int size){
	// 数组中第一个元素作为待排序的数字，start和end之间的数字进行位置调整
	int base = *p_val;
	int* start = p_val;
        int* end =p_val+size-1;
	//结束递归的条件
	//或者start = end是
	if(size<=1){
		return ;
	}
	// start == end 是start前面的数字比start小，后面的数字比start大	
	while(start <end){
		if(*start>*end){
			int temp = *start;
		        *start = *end;
			*end = temp;	
		}
		// 将那个和待排序的数字比较过的数字排除在外
		if(*start == base){
			// *end的数字是和待排序的数字比较的数字
			end--;
		}else{
			start++;
		}
	}
	// 排序过后，上面的数字start=end;*start前面的数字比*start小，后面的数字比*start大；
	// 对start前面和后面额数字进行快速排序
	quick_sort(p_val,start-p_val);
	quick_sort(start+1,size-(start-p_val)-1);
}
int main(){
	int arr[] = {60,30,10,80,50,100,20};
	int size =sizeof(arr)/sizeof(arr[0]);
	// bubble_sort(arr,size);
	// choice_sort(arr,size);
	// insert_sort(arr,size);
	quick_sort(arr,size);
	for(int i=0;i<=size-1;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
	return 0;
}
