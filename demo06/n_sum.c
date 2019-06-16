//
// Created by 86177 on 2019/6/1.
//  计算1+2+3+4+。。。n的和
//

//sum(n) = n+ sum(n-1)

#include <stdio.h>

int sum(int n){
    if(n==1)
        return 1;
    else
        return n+sum(n-1);
}

int  main(){
    int n=10;
    printf("请输入一个数字：");
    scanf("%d",&n);
    int res = sum(n);
    printf("%d",res);
    return 0;
}
