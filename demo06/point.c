//
// Created by 86177 on 2019/6/1.
//

#include <stdio.h>



int main(){
  int a = 10;
  char c = 11;
  int* p =&a;
  char* q =&c;
  //4
  printf("%d\n", sizeof(p));
  //4
  printf("%d\n", sizeof(q));
  return 0;
}


