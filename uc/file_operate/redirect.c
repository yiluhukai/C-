/*
 *	dup和dup(2)实现文件重定向
 */
#include "t_file.h"
#include <string.h>
int main(int argc,char* argv[]){
	char * msg="I am test....";
	// 打开一个文件
	int flag =  O_WRONLY|O_CREAT|O_TRUNC;
	// fd = 3
	int fd = open(argv[1],flag,0644);
	if(fd == -1){
		perror("open");
		return -1;
	}
	// 将标准输出复制到4的位置
	int s_fd = dup(1);
	// 将1的位置指向这个文件
	dup2(3,1);
	// 关闭3的文件描述符
	close(3);
	// 输出内容到打开的文件
	write(1,msg,strlen(msg));
	
	//恢复现场
	close(1);
	// 将4的文件描述符指向1
	dup(s_fd); 
	// 关闭4
	close(s_fd);
	// 输出内容到标准输出
	write(1,msg,strlen(msg));
	return 0;
}
