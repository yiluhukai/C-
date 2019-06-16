//
// Created by 86177 on 2019/5/31.
//
//  创建一个求绝对值的函数
#include <stdio.h>
int myabs(int n) {
    if (n < 0) {
        n = -n;
    }
    return n;
}

int main() {
    int num = -20;
    printf("请输出一个数");
    scanf("%d", &num);
    int cal_num = myabs(num);
    printf("|%d|=%d\n", num, cal_num);
    return 0;
}
