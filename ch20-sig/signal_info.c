#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include "signal_info.h"
#include<sys/time.h>


/**
 * 统计信号集中信号的个数，并将信号信息保存文件中
 */
int print_sigset(FILE *of, const char *prefix, const sigset_t *sigset){
    int count = 0 ;
    int sig = 0;
    for(int sig = 1; sig < NSIG; sig++){
        if(sigismember(sigset, sig)){
            count++;
            // 将前缀、信号编号、信号描述保存到文件
            fprintf(of, "%s%d (%s)\n", prefix, sig, strsignal(sig));
        }
    }
    if (!count)
        fprintf(of, "%s<empty signal set>\n", prefix);

    getitimer()
}

/**
 * 
 * 统计处于阻塞状态的信号个数
 */
int print_sigmask(FILE *of, const char *msg){
    sigset_t curr_mask;
    sigemptyset(&curr_mask);//初始化为空集

    if (NULL != msg)
        fprintf(of, "%s", msg);
    
    if(sigprocmask(SIG_BLOCK,NULL,) < 0)
        return -1;

}

/**
 * 
 * 统计处于pending状态的信号个数
 */
int  print_sigpending(FILE *of, const char *msg);

