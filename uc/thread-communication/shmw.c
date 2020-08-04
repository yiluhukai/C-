/*
 *
 *	ftok创建一个system v key
 *
 *
 */



#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h> 
#include <sys/shm.h> 
#include <string.h>
int main(){
	key_t key  = ftok(".",23);
	if(key == -1){
		perror("ftok");
		return -1;
	}

	printf("key:0x%x\n",key);
	int shmid = shmget(key,1024,IPC_CREAT|0644);
	if (shmid == -1){
		perror("shmget");
		return -1;
	}
	// 
	void * address = shmat(shmid,NULL,0);
	
	if(address == (void *)-1){
		perror("shmat");
		return -1;
	}
 	
	//
	strcpy((char*) address,"I am testing ...." );
	shmdt(address);
	return 0;
}
