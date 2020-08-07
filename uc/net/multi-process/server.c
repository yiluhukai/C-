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
int main(){

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
	//  
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
			//  非阻塞等待
			waitpid(-1,NULL,WNOHANG);	
		}

	
	}
	return 0;
}
