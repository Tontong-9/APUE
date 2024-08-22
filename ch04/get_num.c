#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include<time.h>

#include "get_num.h"
#include "get_curtime.h"


#define DEFAULT_TIME_FORMAT "%Y/%m/%d %H:%M:%S"

/* error handling */
void gn_fail(const char* fname, const char* msg,int flags,const char* arg,const char* name){
    char* curtime = get_curtime(DEFAULT_TIME_FORMAT);
    if(curtime!=NULL){
        fprintf(stderr,"[APUE] %s [D] [%s|%s]",curtime,__FILE__,fname);
        free(curtime);
    }

    if (name != NULL)
    fprintf(stderr, " (in %s)", name);
    fprintf(stderr, ": %s\n", msg);
    if (arg != NULL && *arg != '\0')
        fprintf(stderr, "        offending text: %s\n", arg);

    exit(EXIT_FAILURE);
}

char* get_curtime(const char* fmt){
    const char* curtime = (char)malloc(128);
    if (curtime == NULL) {
        // 处理内存分配失败的情况
        perror("Memory allocation failed");
        return NULL;
    }
    time_t t = time(NULL);
    struct  tm* tm_ptr = localtime(&t);
    size_t strlen = strftime(curtime,128,fmt==NULL?DEFAULT_TIME_FORMAT:fmt,tm_ptr);
    if(!strlen){
        free(curtime);
        return NULL;;
    }
    return curtime;
}
int getInt(const char* arg,int flags,const char* name){

    return (int)arg;
}
int main(int argc, char *argv[])
{
	int fd;
	char buf[1024];
	int n;
	if(argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if(fd < 0)
	{
		perror("open");
	}
}