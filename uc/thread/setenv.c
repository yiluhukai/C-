/*
 *
 *
 *	setenv和putenv
 *
 *
 */
#include <stdlib.h>
#include <stdio.h>
void setEnv(){
	char name[] = "name";
	char value[] = "nanjing";
	char s[20] = {};
	sprintf(s,"%s=%s","caption","beijing");
       	setenv(name,value,1);
	int res =putenv(s);
	//int res =putenv("name=nanjing");
	if(res==-1){
		perror("setenv");
	}		
}

int main(){
	setEnv();
	printf("name=%s\n",getenv("name"));
	printf("caption=%s\n",getenv("caption"));

	unsetenv("name");
	printf("name=%s\n",getenv("name"));
	return 0;
}
