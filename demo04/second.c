/*
 *输入一个秒数，返回对应的小时、分钟、秒数，
 *
 */
#include<stdio.h>
int main(){
	int second=0,hour = 0,min = 0, sec =0;
 	printf("请输入一个秒数");
	scanf("%d",&second);
	hour = second / 3600;
	min = (second - hour*3600)/60;
	sec = second % 60;
	//%02d的意思输入占两位，不够的补0；
	printf("%d:%02d:%02d\n",hour,min,sec);
	return 0;
}
