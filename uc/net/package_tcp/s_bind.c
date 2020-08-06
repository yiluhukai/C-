/*
 *	
 *	基于tcp的服务器
 *	
 */
#include "t_net_tcp.h"

int s_bind(int domain,int type,short int port){

	// 创建一个用于通信的socket
	ipv4_addr addr;
	int  sfd =  socket(domain,type,0);

	if(sfd==-1){
		perror("socket");
		return -1;
	}
	// 绑定具体的地址
	addr.sin_family =AF_INET;
	addr.sin_port =  htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;
	int res =  bind(sfd,(normal_addr *)&addr,sizeof(addr));
	if(res == -1){
		perror("bind");
		return -1;
	}

	return sfd;
}
