#include "t_ls.h"
int main(int argc,char * argv[]){
	if(argc != 3 ){
		printf("invlid args\n");
		return -1;
	}
	char * path =argv[2];
	printf_all_meta_message(path);
	return 0;
}
