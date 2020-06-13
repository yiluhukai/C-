/*
 *
 *  获取文件的元信息
 *
 *
 *
 * */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
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
	printf("uid of user:%u,username: %s\n",st.st_uid,getpwuid(st.st_uid)->pw_name);
	//
	printf("gid of user:%u,username:%s\n",st.st_gid,\
			getgrgid(st.st_gid)->gr_name);
	printf("access time of last:%ld\n",st.st_atim.tv_sec);
	printf("access time of last:%ld\n",st.st_atime);
	printf("access time of last :%s",ctime(&(st.st_atime)));
	printf("mode of file:%o\n",st.st_mode);
	printf("File type:                ");

           switch (st.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }

	return 0;
}
