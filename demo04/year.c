/*
 *	判断一年是不是闰年：1.能被4整除但不能被100整除
 *		            2.能被400整除		
 *
 */

#include <stdio.h>


int main(){
	int year = 0;
	printf("请输入一个年份:\n");
	scanf("%d",&year);
	year%4 == 0 && year%100 != 0 || year %400 ==0?printf("闰年\n"):printf("不是闰年\n");
	return 0;
}
