//
// Created by 86177 on 2019/6/5.
//


#include "stdio.h"

int main(){
    char * str= "absd";
    char a[12] = "sdasdasd";
    //str指针指向a数组，负责使用指针会修改字符串常量
    str = a;
    //输入带有空格或者回车符的字符串会被截断
    scanf("%s",str);//
    printf("%s\n",str); //
    return 0;
}
