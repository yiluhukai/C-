/*
 *
 *
 *	基于udp的编程
 *
 */
#include <ctype.h>
#include "t_net_tcp.h"
int main(){
	char buff[128];
	char ip[128];
	ipv4_addr addr;
	socklen_t addr_len;
	int sfd = s_bind(AF_INET,SOCK_DGRAM,8080);
	if(sfd ==-1){
		return -1;
	}
	// 接受客户端发送过来的信息
	while(1){
		addr_len = sizeof(addr);	
		ssize_t r = recvfrom(sfd,buff,128,0,(normal_addr *)&addr,&addr_len);
		if(r==-1){
			perror("recvfrom");
			return -1;
		}
		printf("soruce address:%s\n",inet_ntop(AF_INET,&addr.sin_addr.s_addr,ip,128));
		//  转大写
		for(int i=0;i<r;i++){
			buff[i]= toupper(buff[i]);
		}
		r= sendto(sfd,buff,r,0,(normal_addr *)&addr,sizeof(addr));
		if(r==-1){
			perror("sendto");
			return -1;
		}
	}
	return 0;
}
