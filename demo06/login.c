//
// Created by 86177 on 2019/5/31.
// 接受用户的输入，验证密码，成功返回1；失败返回3次返回0
//
#include "stdio.h"

int login() {
    int password = 1235;
    printf("please input password\n");
    int count = 3;
    int pwd = 0;
    while (count > 0) {
        scanf("%d", &pwd);
        if (pwd == password) {
            return 1;
        } else {
            printf("plese input again!\n");
            count--;
        }
    }
    return 0;
}

int main() {
    int result = login();
    if (result == 1) {
        printf("login successfully！");
    } else {
        printf("login error");
    }
    return 0;
}
