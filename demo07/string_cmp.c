//
// Created by 86177 on 2019/6/6.
//
// 字符串的比较方法  strcmp;

#include "stdio.h"
#include "string.h"

int main(){
    char * str1 = "hello";
    char * str2 = "Hello";
    int p = strcmp(str1,str2);
    printf("%d",p);//1
    return 0;
}
