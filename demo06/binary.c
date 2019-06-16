//
// Created by 86177 on 2019/6/1.
// 10进制转2进制数
//  方法：11/2=5   11%2=1  第一位
//        5/2 =2    5%2 =1  第二位
//        2/2 =1    2%2 =0   第三位
//        1%2         = 1     第四位


#include "stdio.h"
//递归的方法
void ten2bit(int n){
    //商为0
    if(n==0){
        return ;
    }
    int m = n/ 2;
    ten2bit(m);
    int rest = n % 2;
    printf("%d",rest);

}

//非递归的方法
void ten_to_bit(int n){
    int size = sizeof(n)*8;
    int arr[size];
    int length = 0;
    while(n!=0){
        arr[length++] = n%2;
        n = n/2;
    }
    for(int i=length-1;i>=0;i--){
        printf("%d",arr[i]);
    }
}
int main(){
    int n = 0;
    printf("请输入一个数：\n");
    scanf("%d",&n);
    //ten2bit(n);
    ten_to_bit(n);
    return 0;
}