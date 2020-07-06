#include <stdio.h>

int main(){
	union {
	char  c;
	short int s_i; 
	}u;
	u.s_i = 0x0102;
	if(u.c == 01){
	   printf("大端");
	}else{
	  printf("小端");		
	}

}
