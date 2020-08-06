/*
 *
 *	基于tcp连接的客户端
 *
 *
 */
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
	char buff[128];
	char * msg = "this is my first connect\n";
	struct sockaddr_in addr;
	int sfd =  socket(AF_INET,SOCK_STREAM,0);
	if(sfd == -1) {
		perror("socket");
		return -1;
	}
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);
	//addr.sin_addr = INADDR_LOOPBACK;
	inet_pton(AF_INET,"127.0.0.1",&addr.sin_addr);
	//  创建新的连接
	int res = connect(sfd,(struct sockaddr*)&addr,sizeof(addr));
	if(res == -1){
		perror("connect");
		return -1;
	}
	//向服务器端写入内容
	write(sfd,msg,strlen(msg));
	// 等待服务器端的响应
	int r= read(sfd,buff,128);
	//  输出内容到屏幕
        write(1,buff,r);
	close(sfd);	
	return 0;
}
