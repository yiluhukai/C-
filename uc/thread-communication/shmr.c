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
	printf("shmid:%d\n",shmid);
	void * address = shmat(shmid,NULL,0);
	
	if(address == (void *)-1){
		perror("shmat");
		return -1;
	}
 	
	//
	printf("%s\n",(char *)address);
	shmdt(address);
	return 0;
}
