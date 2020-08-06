#ifndef __T_NET_TCP_H__
#define __T_NET_TCP_H__



#include <sys/types.h> /* See NOTES */ 
#include <sys/socket.h> 
#include <stdio.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

typedef struct sockaddr_in ipv4_addr;
typedef struct sockaddr normal_addr;

int s_bind(int domain, int type,short int port);
void do_request_handle(int fd);
#endif

