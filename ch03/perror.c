#include<stdio.h>
#include <stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

void perror(const char* msg);
int main(){
    int fd = open("./test.txt", O_RDONLY,0664);
    if(fd<0){
        perror("open fail!\n"); //注意！！只有库函数调用和系统调用的函数错误信息  用perror函数输出  它会内部自己去找errno值
        exit(EXIT_FAILURE); //程序异常终止
;    }
    else {
        printf("open success!\n");
        // 操作文件代码
        // 例如读取文件内容等
        close(fd);
    }
    printf("do sth !");
    return 0;
}
void perror(const char* msg){
    printf("\n出错啦，错误信息是：%s\n", msg);
}
/*

文件描述符	用途	POSIX名称	stdio流
0	标准输入	STDIN_FILENO	stdin
1	标准输出	STDOUT_FILENO	stdout
2	标准错误	STDERR_FILENO	stderr

perror >test.txt
perror 2>test.txt

*/