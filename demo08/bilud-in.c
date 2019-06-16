//
// Created by 86177 on 2019/6/8.
//
// 内置宏变量

#include <stdio.h>

int main(){
    printf("%s\n",__FILE__);//.\bilud-in.c
    printf("%d\n",__LINE__);//10
    printf("%s\n",__DATE__);//Jun  8 2019
    printf("%s\n",__TIME__);//22:57:45
    return 0;
}
