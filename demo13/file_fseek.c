/*
 *
 *	向文件中写入内容:使用fseek将文件的流指针指向开始位置
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

	char name[20];
	int age;
	int score;
} Student;



int main(){

	Student s = { "hello",20,80};
    //打开文件
	FILE * f = fopen("data.txt","w+");
	if(NULL == f){
		printf("打开文件失败\n");
	}
	printf("%ld\n",ftell(f));
	//准备写入文件的内容,返回的使已写入的个数
	int i =fwrite(&s,sizeof(Student),1,f);
	printf("写入文件的个数%d\n",i);
	
	// 设置文件流指针的位置
	
	rewind(f);

	//打印文件流指针指向的位置
	printf("%ld\n",ftell(f));
	
	Student a[10]={0};
	//读取文件
	i=fread(a,sizeof(Student),1,f);
	printf("读入文件的个数%d\n",i);
	printf("name=%s\n",a[0].name);
	printf("age=%d\n",a[0].age);
	printf("score=%d\n",a[0].score);
	printf("当前文件流的位置%ld\n",ftell(f));
    
	//fseek(f,-8,SEEK_END);
	//	fseek(f,20,SEEK_SET);
	fseek(f,-8,SEEK_CUR);
	int age = fread(&age,sizeof(int),1,f);
	printf("age=%d\n",a[0].age);
	//修改学生的成绩
	int score=70;
	fwrite(&score,sizeof(int),1,f);
	rewind(f);
	fread(a,sizeof(Student),1,f);
	printf("name=%s\n",a[0].name);
	printf("age=%d\n",a[0].age);
	printf("score=%d\n",a[0].score);
	//关闭文件
	fclose(f);
	f=NULL;
	return 0;
}
