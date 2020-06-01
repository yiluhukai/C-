/*
 *
 *  获取文件的元信息
 *
 *
 *
 * */
# include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main (int argc,char* argv[]){
	const char* path = (const char *)argv[1];
	struct stat st;
	int res =  stat(path, &st);
	if(res==-1){
		perror("stat");
		return -1;
	}
	printf("number of inode:%lu\n",st.st_ino);
	printf("size of file;%lu\n",st.st_size);
	printf("number of  hard link:%ld\n",st.st_nlink);
	return 0;
}
