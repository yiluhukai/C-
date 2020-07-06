#include <stdio.h> 
#include <sys/types.h>
#include <unistd.h>
const int var_g = 100;
int var_global =1000;
void count(){
	static int i = 1;
	printf("%d\t%p\n",++i,&i);
}

int main(){
	printf("var_g address=%p\n",&var_g);
	printf("var_global address=%p\n",&var_global);

	const int s = 20;
	int * const  p = &s;
	*p =100;
	printf("s =%d\n",s);
	printf("s address %p\n",&s);
	printf("PID:%d\n",getpid());
	getchar();
	return 0;
}
