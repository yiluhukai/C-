/*
 *	
 *	枚举类型
 */

#include <stdio.h>

int main(){
	//声明一个枚举类型
	enum SEASON {
		Spring,Summer,Autumn,Winter
	};

	//创建一个枚举变量
	
	enum SEASON  s = Spring;

	//打印输出这个枚举变量
	printf("%d\n",s);
	return 0;
}
