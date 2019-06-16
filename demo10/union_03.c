/*
 *
 * 声明一种联合体类型
 *
 */
#include <stdio.h>
int main(){
	//创建一个联合类型
	typedef union{
	//union Score  {
		char level;
		int i_score;
		double d_score;
	}Score;
	// 声明一个联合体变量
	//union Score s;
	Score s;
	s.i_score = 10;
	printf("%d\n",s.i_score);
	s.d_score = 10.1;
	printf("%f\n",s.d_score);
	s.level = 'A';
	printf("%c\n",s.level);
	return 0;

}
