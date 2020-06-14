/*
 *
 *
 *
 *	实现一个类似ls -ali directory 的shell操作
 *
 *
 *
 * */
#include <sys/types.h> 
#include <dirent.h> 
#include <stdio.h>
#include <errno.h>
#include "t_ls.h"
int main (int argc,char * argv[]){

	if(argc != 3){

		printf("invalid arguments");
		return -1;
	}
	// 打开文件夹
	DIR * dir = opendir(argv[2]);
	// 读取文件夹的内容
	if(NULL == dir){
		perror("opendir");
		return -1;
	}		
	// 读取文件夹的内容
	errno = 0;
	struct dirent * dir_item =NULL;
	while(dir_item = readdir(dir)){
		// printf("%lu-%s\n",dir_item->d_ino,dir_item->d_name);
		char path[256];
		snprintf(path,256,"%s%s%s",argv[2],"/",dir_item->d_name);
		printf_all_meta_message(path);
		printf("\n");
	}
	// 读取文件夹失败
	if(errno !=0 ){
		perror("readdir");
		return -1;
	}

	//关闭文件夹


	int res = closedir(dir);

	if(res == -1){

		perror("closedir");
		return -1;
	}		
	return 0;
}
