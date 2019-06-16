/*
 *
 *  字符串
 *
 */

#include "stdio.h"

int main(){
    //printf("%p","hello");//00405064
    char* str = "hello";
    //为什么是！=0;因为字符串的结尾用'\0'表示，'\0' == 0；
//    while(*str != 0){
//        printf("%c",*str++);  //hello
//    }
//    printf("%d",'\0' == 0);  //1
    *str = 'A';
    printf("%d",*str);
    return 0;
}