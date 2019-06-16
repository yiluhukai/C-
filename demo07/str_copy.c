//
// Created by 86177 on 2019/6/6.
//

#include "stdio.h"
#include "string.h"
int main(){
    char* str ="basdasd";
    char a[]="1234567890";
    //str[i]!=0;
    int i = 0;
    while(str[i]){
        a[i]=str[i];
        i++;
    }
    printf("%s\n",a); //basdasd890

    strcpy(a,str);
    //会复制\n
    printf("%s",a); //basdasd
    return 0;
}