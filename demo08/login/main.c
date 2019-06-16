//
// Created by 86177 on 2019/6/7.
//

// 用户登录系统

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "login.h"

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



