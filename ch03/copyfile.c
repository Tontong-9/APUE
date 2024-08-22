#include<stdio.h>
#include <stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#ifndef BUFSIZE
#define BUFSIZE 1024
#endif
/* 0:copy 1:oldfile 2:newfile*/
int main(int argc,char* argv[]){
    //argc illegal judge!
    if(argc == 1){
        perror("argc < 3! try again!\n");
    }
    if(argc < 3 || strcmp(argv[1],"--help") == 0){
        fprintf(stderr, "%s oldfile newfile \n", argv[0]);
    }
    //open file
    char* buf;
    buf = (char*)malloc(BUFSIZE);
    memset(buf,0,BUFSIZE);
    int fd_old = open(argv[1],O_RDONLY);
    int flags = O_CREAT | O_WRONLY | O_TRUNC;
    int perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; // rw-rw-rw-
    int fd_new = open(argv[2],flags,perms);
    if(fd_old < 0){
        perror("open oldfile error!\n");
    }//operator and close file
    else{
        printf("oldfile open success!");
        ssize_t old_len = read(fd_old,buf,BUFSIZE);
        ssize_t new_len = write(fd_new,buf,old_len);
        while(old_len>0){
            if( new_len != old_len){
                perror("write error!\n");
            }else{
                printf("copy success!\n");
                exit(EXIT_SUCCESS);
            }
        }if(old_len<0) perror("read error!\n");
        if(close(fd_old)<0) fprintf(stderr,"close1 %s error!\n",argv[1]);
        if(close(fd_new)<0) fprintf(stderr,"close2 %s error!\n",argv[2]);
        
    }
    exit(EXIT_FAILURE);
    return 0;
}