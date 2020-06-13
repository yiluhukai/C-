/*
 *
 *  
 *  shell:ls -li hello,achieve same efffect
 *	
 *
 *
 *
 *
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h> 
#include <pwd.h> 
#include <grp.h> 
#include <time.h>
void printf_mode(struct stat st,unsigned int mask_value,char*  c){
	char * mode =  st.st_mode & mask_value ? c :"-";
	printf("%s",mode);	
}

int main(int argc,char * argv[]){
	if(argc != 3 ){
		printf("invlid args\n");
		return -1;
	}
	char * path =argv[2];
	struct stat st;
	if(stat(path, &st)==-1){
		perror("stat");
		return -1;
	};
	// inode
	printf("%lu ",st.st_ino);
	// file type
	//
	switch (st.st_mode & S_IFMT) {
		case S_IFDIR:  printf("d");               break;
		case S_IFREG:  printf("_");            break;
		default:       printf("unknown?\n");                break;
	}
	// mode
	printf_mode(st,S_IRUSR,"r");
	printf_mode(st,S_IWUSR,"w");
	printf_mode(st,S_IXUSR,"x");
	printf_mode(st,S_IRGRP,"r");
	printf_mode(st,S_IWGRP,"w");
	printf_mode(st,S_IXGRP,"x");
	printf_mode(st,S_IROTH,"r");
	printf_mode(st,S_IWOTH,"w");
	printf_mode(st,S_IXOTH,"x");
	printf(" ");

	// hard link number
	printf("%lu ",st.st_nlink);

	// file owner
	printf("%s ",getpwuid(st.st_uid)->pw_name);
	// file goroup
	printf("%s ",getgrgid(st.st_gid)->gr_name);
	//size of file 
	printf("%ld ",st.st_size);
	// access time
	struct tm * time = gmtime(&st.st_atime);
	printf("%d月 ",time->tm_mon+1);
	printf("%d ",time->tm_mday);
	printf("%02d:%02d ",time->tm_hour,time->tm_min);
	printf("%s\n",path);
	return 0;
}
