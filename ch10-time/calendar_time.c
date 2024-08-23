#include<time.h>
#include<sys/time.h>
#include<stdio.h>
int main(){
    clock_t clockt = time(NULL);
    struct tm *tm = localtime(&clockt);
    printf("%ld\n",tm->tm_hour);
    return 0;
}