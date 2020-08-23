/*
 *
 *	处理表单请求 /hello
 *
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(int argc,char* argv[]){
	write(1,argv[1],strlen(argv[1]));
	return 0;
}
