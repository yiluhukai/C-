//
// Created by 86177 on 2019/6/9.
//


// 结构体数组


#include <stdio.h>

typedef struct student{
    char name[20];
    int age;
    int score;
} Student;

void inputFunc(Student * student,int count);
void outputFucn(Student * student,int count);
void inputFunc(Student * student,int count){
    for(int i=0;i<count;i++){
        printf("请输入名字：\n");
        scanf("%s",student[i].name);
        printf("请输入年龄：\n");
        scanf("%d",&student[i].age);
        printf("请输入分数：\n");
        scanf("%d",&student[i].score);
    }
}

void outputFunc(Student * student,int count){
    for(int i=0;i<count;i++){
        printf("第%d个学生的名字：%s\n",i+1,student->name);
        printf("第%d个学生的年龄：%d\n",i+1,student->age);
        printf("第%d个学生的分数：%d\n",i+1,student->score);
        student++;
    }
}
int main(){
    //创建一个结构体数组
    Student students[10];
    inputFunc(students,3);
    outputFunc(students,3);
    return 0;
}

