/*
 *通过sizeof打印变量和常量所占用的字节数。
 *
 */

#include <stdio.h>
int main()
{
  char c;
  int i;
  printf("c占用的字节数：%lu\n",sizeof(c));
  printf("i所占用的字节数：%lu\n",sizeof(i));
  printf("3.14所占用的字节数: %lu\n",sizeof(3.14));
  printf("2所占用的字节数：%lu\n",sizeof(2));
  return 0;
}
