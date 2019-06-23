/*
 *
 *	动态分配一块内存空用来保存结构器
 *
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	char *name;
	int age; 
	//int height;
}Person;

Person *  input(){
	//该空间在函数执行结束时不会释放
	Person * p = (Person *)malloc(sizeof(Person)); 
	printf("%ld\n",sizeof(Person));
	p->name="lijunjie";
	p->age =20;
	//p->height =170;
	return p;
}

void output(Person * p){
	printf("name=%s\n",p->name);
	printf("age=%d\n",p->age);
	//printf("age=%d\n",p->height);
}



int main(){
	Person* pi = input();
	output(pi);
	//释放malloc的内存空间
	free(pi);
	pi= NULL;
	return 0;
}
