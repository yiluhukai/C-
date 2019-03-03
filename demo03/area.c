/*
 *用户输入矩形的长和宽，输出面积和周长
 */

#include <stdio.h>
int main()
{
	float width= 0,height=0;
	printf("请输入矩形的长和高：");
	scanf("%f,%f",&width,&height);
	printf("矩形的面积为%f\n",width*height);
	printf("矩形的周长为%f\n",(width+height)*2);
	return 0;
}
