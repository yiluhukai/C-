/*
 *
 *
 *
 *	printf()
 *
 */


#include  <stdio.h>
#include  <stdlib.h>
typedef struct{
	char name[20];
	int age;
	int score;
}Student;
int main(){
	//printf("hello")
	
	FILE* f =  fopen("124.txt","r+");

	if(!f){
		printf("文件打开失败");
	}
	Student s;
	printf("文件打开成功\n");
    fscanf(f,"%s%d%d",s.name,&s.age,&s.score);
	printf("name=%s\n",s.name);
	printf("age=%d\n",s.age);
	printf("score=%d\n",s.score);
	fclose(f);
	return 0;
}
