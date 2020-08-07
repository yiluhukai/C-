/*
 *
 * 处理请求的函数
 *
 *
 */

#include "t_net_tcp.h"
#include <string.h>
#include <ctype.h>
void do_request_handle(int cfd){
	 char * msg ="receive ok\n";
	 char buff[128]; 
                
         // 从文件描述读取请求内容

         int r = read(cfd,buff,128);

	 for(int i=0;i<r;i++){
	 	buff[i] = toupper(buff[i]);
	 }
         //  输出到屏幕上
         write(cfd,buff,r);
         // 向客户端返回在数据
         write(cfd,msg,strlen(msg));
	 // 模拟复杂业务的处理
	 sleep(10);
	
}
