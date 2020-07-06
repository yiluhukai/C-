/*
 *
 *	
 *	对文件添加读锁
 *
 *
 *
 */

#include "open_file.h"


int main(int argc,char * argv[]){


	// 获取进程的pid
	
	printf("pid %d\n",getpid());

	// 打开一个文件

	int file = open(argv[1],O_RDONLY);

	if(file == -1){
		perror("open");
		return -1;
	}

	//打开成功，设置读锁
	

	struct  flock lock;

	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 10;
	int res =  fcntl(file,F_SETLK,&lock);
	
	if(res == -1){
	
		perror("fcntl");
		return -1;
	}else{
	
		printf("add read lock for file\n");
	}

	getchar();
	//关闭文件
	close(file);
	return 0;

}
