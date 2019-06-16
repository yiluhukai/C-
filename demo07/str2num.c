//
// Created by 86177 on 2019/6/7.
//

//  字符串转数字

// "123"  ---> 123

#include <stdio.h>

int str2num(const char * str){
    int sum =0;
    while(*str >= '0' && *str <= '9'){
         //获取的时字符对应的数字
         int  i = *str - 0x30;
         sum = sum*10+i;
         //指向字符的下一位
         str++;
    }
    return sum;
}

int main(){
    char * a = "124ab";
    int h = str2num(a);
    printf("%d",h);
    return 0;
}
