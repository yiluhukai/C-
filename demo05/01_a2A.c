/*
 *
 *	输入字母（大写/小写），返回对应的小写字母
 */

#include <stdio.h>

int main(){
	char c = 0;
	printf("请输入一个字母:");
	scanf("%c",&c);
	//if(c>=97 && c<=122 )
	if(c>='c' && c<='z')
	{
		c=c-32;
	}
	printf("%c\n",c);
	return 0;
}
