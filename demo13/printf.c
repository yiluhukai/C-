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
    fwrite("hello",sizeof(char),6,stdout);  
	
	FILE* f =  fopen("123.txt","w+");

	if(!f){
		printf("文件打开失败");
	}
	printf("文件打开成功");
    fprintf(f,"hello");
    Student s = {"name",24,90};
	fprintf(f,"%s,%d,%d",s.name,s.age,s.score);
	fclose(f);
	return 0;
}
