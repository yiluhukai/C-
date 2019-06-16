//
// Created by 86177 on 2019/6/7.
//

// 用户登录系统

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void setPasswd(char * passwd){
    printf("请输出你要使用的密码：\n");
    scanf("%s",passwd);
}

int loginIn(const char*  passwd){
    int i =3;
    //不能使用字符指针去直接保存，会产生野指针（char * str; ）
    char  a[13] ={0};
    while(i>0){
        printf("请输入你的密码：\n");
        scanf("%s",a);
        printf("s=%s",passwd);
        printf("a=%s",a);
        if(strcmp(passwd,a)==0){
            return 1;
        }else{
            i--;
        }
    }
    return 0;
}

void operation(){
    printf("+-----------------+\n");
    printf("+     操作方式：  +\n");
    printf("+   1.设置密码    +\n");
    printf("+   2.去登陆      +\n");
    printf("+   0. 退出系统   +\n");
    printf("+-----------------+\n");
}
