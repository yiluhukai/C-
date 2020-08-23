/*
 *
 * 处理请求的函数
 *
 *
 */

#include "t_net_tcp.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

char*  work_path = "/home/bruce/C-/uc/web-server/public";

static void  get_request(int cfd,req_t * req){
	char buff[1024];
	char path[128];
	int r = read(cfd,buff,1024);
	
	if(r==-1){
		perror("read");
		return;
	}

	printf("\nrequest --- content\n");

	write(1,buff,r);
	printf("\nresquest --- end\n");		
	// 协议的第一行解析到结构体中
	sscanf(buff,"%s %s %s",req->method,req->path,req->protocol);


	//  处理请求文件的路经问题
	if(strcmp(req->path,"/")==0){
		strcpy(req->path,"/index.html");
	}
	strcpy(path,work_path);
	strcat(path,req->path);
	strcpy(req->path,path);
}


static char* get_file_type(req_t req){
	char *path =  req.path;
	if(strcmp(strrchr(path,'.'),".png")==0){
		return "image/png";
	}else if(strcmp(strrchr(path,'.'),".jpg")==0){
		return "image/jpg";
	}else{
		return "text/html";
	}
}
/*
 *
 *	获取协议信息，状态码和文件的类型
 *
 */
static void response_handle(req_t req,resp_t * res){
	// 根据请求信息生成响应	
	// 获取请求的参数
	res->req= req;
	// 根据文件是否存在返回响应状态码
	res->statusCode = access(req.path,R_OK)?404:200;
	
	char * contentType =NULL;
	if(res->statusCode !=200){
		contentType="text/html";
	}else{
		contentType = get_file_type(req);	
	}
	strcpy(res->contentType,contentType);

	
}
/*
 *
 *	返回内容给客户端：
 *	协议 状态码
 *	文件的类型
 *	文件的内容
 *
 */

void static response_ok(int cfd,resp_t* res){
	char protocol_and_code[128];
	char cont[128];
        sprintf(protocol_and_code,"%s %d %s\r\n",res->req.protocol,res->statusCode,"ok");
	sprintf(cont,"%s:%s\r\n\r\n","Content-Type",res->contentType);
	write(cfd,protocol_and_code,strlen(protocol_and_code));
        write(cfd,cont,strlen(cont));
	//  将文件写入到cfd
	dup2(cfd,1);
	execlp("cat","cat",res->req.path,NULL);
	perror("execlp");
}
void static response_err(int cfd,resp_t* res){
	char protocol_and_code[128];
	char cont[32];
	char * errMsg="<html> <head><title> 404 page</title></head><body>file not found!</body> </html>";
        sprintf(protocol_and_code,"%s %d\r\n",res->req.protocol,res->statusCode);
        sprintf(cont,"Content-Type:%s\r\n\r\n","text/html");
	write(cfd,protocol_and_code,strlen(protocol_and_code));
	write(cfd,cont,strlen(cont));
	write(cfd,errMsg,strlen(errMsg));
}
// 将参数解析为args 或者 环境变量传入可执行的程序
//
void static response_query(int cfd,resp_t* res){
	char protocol_and_code[128];
        char cont[128];
        sprintf(protocol_and_code,"%s %d %s\r\n",res->req.protocol,res->statusCode,"ok");
        sprintf(cont,"%s:%s\r\n\r\n","Content-Type",res->contentType);
        write(cfd,protocol_and_code,strlen(protocol_and_code));
        write(cfd,cont,strlen(cont));
	char args[128];
	sscanf(res->req.path,"%*[^?]?%s",args);
	printf("args=%s",args);
	dup2(cfd,1);
	execl("./hello","./hello",args,NULL);
	perror("execlp");
}
static void response(int cfd,resp_t* res){
	printf("hello -----------------------------------------------hello\n");
	printf("strstr= %s\n",strstr(res->req.path,"/hello"));
	if(strstr(res->req.path,"/hello")){
		res->statusCode = 200;
		response_query(cfd,res);
		return;
	}

	if(res->statusCode == 200 ){
		response_ok(cfd,res);
	}else{
		response_err(cfd,res);
	}
}

void do_request_handle(int cfd){
	 req_t req; 
	 resp_t res;
                
         // 从文件描述读取请求内容
         get_request(cfd,&req);
	 //printf("methd =%s path=%s protocol=%s\n",req.method,req.path,req.protocol);

	 // 处理请求信息
	 response_handle(req,&res);
	 printf("status-code:%d file-type=%s\n",res.statusCode,res.contentType);
	 response(cfd,&res);

}	
