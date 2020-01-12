/*
 *	
 *	动态加载动态库
 *	
 */



#include <stdio.h>
#include <dlfcn.h>
typedef int (*p)(int,int);

int main(void){
	void * handle = dlopen("libtmath.so",RTLD_NOW);
	if(handle == NULL){
		printf("load error:%s\n",dlerror());
		return -1;
	}
	printf("load successfully\n");
	// 调用动态库中的函数
	void * f = dlsym(handle,"k_add");
	if(f == NULL){
		printf("%s\n",dlerror());
		return -1;
	}
	// 调用动态库中的函数
	printf("2+3=%d\n",((p)f)(2,3));
	dlclose(handle);
	return 0;
}
