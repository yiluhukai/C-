/*
 *
 *将n个苹果分给6个同学，没人平均几个。还剩几个
 *
 */

#include <stdio.h>

int main()
{
	int num = 0;
	//输入苹果的个数
	scanf("%d",&num);
	int average = num / 6;
	int left =num % 6;
	printf("每个人平均分多少个%d\n",average);
	printf("还剩下多少个%d\n",left);
	return 0;
}
