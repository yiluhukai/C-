/*
 *	
 *	基于tcp的服务器
 *	
 */

#include <sys/types.h> /* See NOTES */ 
#include <sys/socket.h> 
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

int main(){

	char buff[128];
	char * msg ="receve oka\n"; 
	// 创建一个用于通信的socket
	struct sockaddr_in addr;
	// 接受客户端socket的addr
	struct sockaddr_in client;
	socklen_t addrlen =(socklen_t)sizeof(client);
	char ip[128];
	int  sfd =  socket(AF_INET,SOCK_STREAM,0);

	if(sfd==-1){
		perror("socket");
		return -1;
	}

	// 绑定具体的地址
	addr.sin_family =AF_INET;
	addr.sin_port =  htons(8080);
	addr.sin_addr.s_addr = INADDR_ANY;
	int res =  bind(sfd,(struct sockaddr*)&addr,sizeof(addr));
	if(res == -1){
		perror("bind");
		return -1;
	}

	// 将socket 设置为被动监听状态
	// 未决队列的最大容量为5
	res = listen(sfd,5);

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
		int cfd = accept(sfd,(struct sockaddr *)&client,&addrlen);
		
		// 打印客户端的地址信息,需要经ip地址从binary 转到字符串
		printf("%s\n",inet_ntop(AF_INET,&client.sin_addr,ip,128));
		
		// 从文件描述读取请求内容

		int r = read(cfd,buff,128);
		//  输出到屏幕上
		write(1,buff,r);
		// 向客户端返回在数据
		write(cfd,msg,strlen(msg));

		// 关闭这个连接
		close(cfd);
	
	}
	return 0;
}
