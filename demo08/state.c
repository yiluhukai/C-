//
// Created by 86177 on 2019/6/8.
//

// 条件编译
#include <stdio.h>
#define WIN 1
#undef WIN
int main(){
#if WIN
    int s= 10;
#else
    int s = 5;
#endif
    printf("%d",s); //5
    return 0;
}
