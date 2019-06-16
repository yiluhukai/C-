//
// Created by 86177 on 2019/6/9.
//
// 使用结构体

#include <stdio.h>
#include <string.h>
int main(){

    //定义一个student类型
    typedef struct student{
        char name[15];
        int age;
        int score;
    }Student;
    //声明一个该类型的变量
//    struct student stu1;
//    //使用结构体
//    // stu1.name="lijunjie"; 不能去修改数组指向的地址
//    strcpy(stu1.name,"lijunjie");
//    stu1.age =23;
//    stu1.score=120;
    Student stu1= {"lijunjie",23,120};
    printf("%s\n",stu1.name); //"lijunjie"
    printf("%d\n",stu1.age); //23
    printf("%d\n",stu1.score); //120

    //定义一个结构体指针
    Student * ps = &stu1;
    printf("%d\n",ps->age);
    (*ps).age = 20;
    printf("%d\n",ps->age);
    printf("%d", sizeof(stu1));
    return 0;
}

