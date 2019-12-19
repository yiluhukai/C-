/*
 *	查找算法
 *
 */
 #include <stdio.h>
 // 折半查找
 int* half_search(const int* p_val,int size,int val){
 	const int* p_start = p_val,*p_end=p_val+size-1,*p_mid = NULL;	
 	//一直查找到p_end<p_start
	while(p_start<=p_end){
		p_mid = p_start+(p_end-p_start+1)/2;
		if(*p_mid == val){
			return (int*)p_mid;
		}else if(*p_mid<val){
			//后半部分查找
			p_start=p_mid+1;
		}else{
			p_end = p_mid-1;	
		}	
	}
	return NULL;
 }

 int main(){
	int arr[] ={10,20,30,50,60,100,150};
       	int* index= half_search(arr,7,100);
	if(index){
		printf("arr[index]=%d\n",*index);
	}else{
		printf("没找到100");
	}	
 	return 0;
 }
