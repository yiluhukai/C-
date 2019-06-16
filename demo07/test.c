//
// Created by 86177 on 2019/6/7.
//
#include <stdio.h>
int main(){
   //
   int a =10;
   int * p = &a;
   printf("%p\n",p);
   int** x =p;

    return 0;
}