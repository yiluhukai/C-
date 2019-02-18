/*
 * char存在整形数据；
 * '0'不等于0
 */
#include <stdio.h>
int main()
{
  char c;
  c=300;
  signed char d;
  d=200;
  printf("%d\n",c);
  printf("%d\n",d);
  char e='0';
  char f=0;
  printf("%d\n",e);
  printf("%d\n",f);
  printf("%s\n",f);
  return 0;
}
