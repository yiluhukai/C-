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
	return 0;
}
