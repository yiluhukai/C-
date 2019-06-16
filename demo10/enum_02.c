/*
 *
 *		使用枚举变量来代表性别
 *
 */

#include <stdio.h>
// 声明一个枚举类型
typedef enum {
	male = 1,
	female

} Gender;
// 声明一个结构体类型
typedef struct{
	char name[10];
    int age;
	Gender gender;
} People;


void printfGender(Gender s);
int main(){
			
	People p = {"kate",20,male};
	printfGender(p.gender);
	return 0;
}
// 打印性别
void printfGender(Gender s){
	if(s == male){
		printf("男性\n");
	}else{
		printf("女性\n");
	}
}
