#ifndef __T_ls__H__
#define __T_ls__H__
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>


void printf_mode(struct stat st,unsigned int mask_value,char*  c);
int printf_all_meta_message(char * path);
#endif
