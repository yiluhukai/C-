/*
 *	将文件或者文件的一部分映射到虚拟地址。
 */

#include "t_file.h"
#include <sys/mman.h>
int main(int argc,char * argv[]){
	//打开一个文件
	int fd = open(argv[1], O_RDWR);
	if(fd == -1){
		perror("open");
		return -1;
	}
	int prot =  PROT_READ|PROT_WRITE;  
	void* p = mmap(NULL, 6,prot, MAP_SHARED ,fd ,0);
	if(p==MAP_FAILED){
		perror("mmap");
		return -1;
	}
	// 映射完成，关闭文件
	close(fd);
	// 对文件的映射区域的内容进行读取
	// 小端的话；修改的文件内容为4321,大端的话为1234
	*((int *)p) = 0x31323334;
	// 取消映射
	munmap(p,6);
	return 0;
}
