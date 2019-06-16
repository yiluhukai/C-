//
// Created by 86177 on 2019/5/30.
//

#include <stdio.h>

//声明函数调用
void printf_stars();

int main() {
    //调用函数
    printf_stars();
    return 0;
}

//打印※
void printf_stars() {
    for (int i = 1; i < 6; i++) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
}


