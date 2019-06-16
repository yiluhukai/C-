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
int main(){
    char a[13] = {0};
    int c= 0;
    int isEnd = 1;
    while(isEnd){
        operation();
        scanf("%d",&c);
        switch (c){
            case 1:{
                setPasswd(a);
                system("cls");
                break;
            }
            case 2:{
                if(loginIn(a)==1){
                    system("cls");
                    printf("登陆成功");
                }else{
                    system("cls");
                    printf("登陆失败");
                }
                break;
            }
            case 0:{
                printf("退出登录");
                isEnd =0;
                break;
            }
            default:{
                printf("操作有误");
                isEnd = 0;
            }
        }
    }
    return 0;
}

