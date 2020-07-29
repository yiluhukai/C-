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
#include <unistd.h>

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
	msgbuff  buf = {0};
	int r = msgrcv(msg_id,&buf,128,3,0);

	if (r == -1){
		perror("msgsnd");
		return -1;
	} 
	write(1,buf.mtext,r);
	return 0;
}
