//
// Created by 86177 on 2019/6/8.
//
#include <stdio.h>
int main(int argc,char * argv[]){
    //打印命令行输入的参数
    for(int i = 0;i<argc;i++){
        printf("%s\n",argv[i]);
    }
    return 0;
}
