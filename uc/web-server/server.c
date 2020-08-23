/*
 *	
 *	基于tcp的服务器
 *	
 */

#include <stdio.h>
#include <string.h>
#include "t_net_tcp.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
void handle_child(int signal_num){
	// 对子进程的资源进行回收
	// printf("signal_num:%d\n",signal_num);
	wait(NULL);
}

int main(){
	// 处理子进程结束的信号
	signal(SIGCHLD,handle_child);
	// 接受客户端socket的addr
	ipv4_addr client;
	socklen_t addrlen =(socklen_t)sizeof(client);
	char ip[128];

	int sfd =s_bind(AF_INET,SOCK_STREAM,8080);
	if(sfd ==-1){
		return -1;
	}
	// 将socket 设置为被动监听状态
	// 未决队列的最大容量为5
	int res = listen(sfd,5);

	if (res == -1){
		perror("listen");
		return -1;
	}
	
	printf("listen successfully\n");
	while(1){
	 	// 当未决队列为空时，处于阻塞状态，
		// 否则取出第一个请求连接
		// 不获取客户端socket的地址和大小
		// 创建一个新的socket文件描述符
		//int cfd = accept(sfd,NULL,NULL);
		//获取客户端的地址
		int cfd = accept(sfd,(normal_addr *)&client,&addrlen);
		
		// 打印客户端的地址信息,需要经ip地址从binary 转到字符串
		printf("%s\n",inet_ntop(AF_INET,&client.sin_addr,ip,128));
		
		// 启用多进程去处理请求


		int pid = fork();
		if(pid == -1){
			perror("fork");
			return -1;
		}
		if(pid == 0){
			// 子进程
			close(sfd);
			do_request_handle(cfd);
			close(cfd);
			exit(1);

		}else{
			close(cfd);
			//  非阻塞等待,但是有可能等不到子进程退出自己先返回了：这时候会产生僵尸进程
			//waitpid(-1,NULL,WNOHANG);	
			//更好的办法是父进程上注册一个信号处理函数，当子进程终止时给父进程发送一个信号，触发信号处理函数去处理这个

		}

	
	}
	return 0;
}
