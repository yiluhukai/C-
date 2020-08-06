/*
 *
 * 处理请求的函数
 *
 *
 */

#include "t_net_tcp.h"
#include <string.h>
void do_request_handle(int cfd){
	 char * msg ="receive ok\n";
	 char buff[128]; 
                
         // 从文件描述读取请求内容

         int r = read(cfd,buff,128);
         //  输出到屏幕上
         write(1,buff,r);
         // 向客户端返回在数据
         write(cfd,msg,strlen(msg));
	
}
