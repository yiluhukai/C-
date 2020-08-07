/*
 *
 *
 *	基于udp客户端
 *
 */
#include "t_net_tcp.h"
#include <string.h>
int main(){
	int sfd = socket(AF_INET,SOCK_DGRAM,0);
	ipv4_addr addr={0};
	char * msg ="this is test\n";
	char buff[128];
	if(sfd == -1){
		perror("socket");
		return -1;
	}
	// 向服务器段发送数据
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);
	int res =inet_pton(AF_INET,"127.0.0.1",&addr.sin_addr);
	if(res !=1){
		printf("tannform for addr failed\n");
		return -1;
	}
	ssize_t r = sendto(sfd,msg,strlen(msg),0,(normal_addr *)&addr,sizeof(addr));
	if(r==-1){
		perror("sendto");
		return -1;
	}
	r= recvfrom(sfd,buff,128,0,NULL,NULL);
	if(r==-1){
		perror("recvfrom");
		return -1;
	}
	close(sfd);
	write(1,buff,r);
	return 0;
}
