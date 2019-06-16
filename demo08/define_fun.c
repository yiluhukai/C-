//
// Created by 86177 on 2019/6/8.
//
#include <stdio.h>
#define DOUBLE(n)  n+n
#define ABS(a)  ((a)>=0?(a):-(a))
int main(){
    int s = DOUBLE(5)*2;// 15
    printf("%d\n",s);
    int n = -10;
    printf("%d",ABS(n));//10
    return 0;
}

