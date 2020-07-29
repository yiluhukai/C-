/*
 *
 *	ftok创建一个system v key
 *
 *
 */



#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/msg.h>
#include <string.h>
typedef struct msgbuf { 
	long mtype; /* message type, must be > 0 */ 
	char mtext[128]; 
} msgbuff; 


int main(){
	key_t key  = ftok(".",23);
	if(key == -1){
		perror("ftok");
		return -1;
	}

	printf("key:0x%x\n",key);
	
	int msg_id =  msgget(key,IPC_CREAT|0644);
	if(msg_id == -1){
		perror("msgget");
		return -1;
	}
	
	printf("msg_id=%d\n",msg_id);
	char * msg ="hello world";
	msgbuff  buf = {0};
	buf.mtype = 3;
	strcpy(buf.mtext,msg);
	int res = msgsnd(msg_id,&buf,strlen(msg),0);

	if (res == -1){
		perror("msgsnd");
		return -1;
	} 
	return 0;
}
