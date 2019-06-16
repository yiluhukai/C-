/*
 *
 *  静态局部变量
 *
 */

#include "stdio.h"
int i =10;  //全局变量
void stat_func(){
    static int i = 10;
    printf("%d\n",i++);
    printf("%p\n",&i); //打印地址
}

int main(){
  stat_func(); //10
  stat_func();//11
  stat_func();//12
  return 0;
}
