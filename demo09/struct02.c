//
// Created by 86177 on 2019/6/9.
//

#include <stdio.h>

typedef  struct student {
    char name[20];
    int age;
    int score;
} Student;
Student fixStudent (Student s){
    s.age=30;
    return s;
}
int main(){
    Student stu ={0};
    stu=fixStudent(stu);
    printf("%s\n",stu.name);
    printf("%d\n",stu.age);//30
    printf("%d\n",stu.score);
    return 0;
}