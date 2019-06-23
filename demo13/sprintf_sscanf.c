/*
 *
 *	sprintf和sscanf()
 *
 */


#include <stdio.h>
#include <stdlib.h>


int main(){
    
    char* str =(char *)calloc(sizeof(char),20);	
	if(!str){
		printf("分配内存空间失败！");
		return -1;
	}
	sprintf(str,"%s", "lijunjie 24 80");
	//
	typedef struct{
		char name[20];
		int age;
		int score;
	}Student;

	// 写入字符串的内容到结构体中；
	Student s ={0};
	sscanf(str,"%s%d%d",s.name,&s.age,&s.score);
	printf("name=%s\n",s.name);
	printf("age=%d\n",s.age);
	printf("score=%d\n",s.score);
	free(str);
	str=NULL;
	return 0;
}
