/*
 * 接受一个小写字母，打印出其对应的大写字母。
 */

#include <stdio.h>

int main()
{
  char lowAlph;
  scanf("%c",&lowAlph);
  printf("%c",(char)(lowAlph-32));
  return 0;
}
