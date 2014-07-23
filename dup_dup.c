/*************************************************************************
	> File Name: dup_dup.c
	> Author: xuxiaoqiang
	> Mail:353271054@qq.com 
	> Created Time: 2014年07月23日 星期三 20时42分42秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>

#define ERR_EXIT(m)\
    do{\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    char buf[100];
    int nread;
    int fd=open("test.txt",O_RDONLY);
    if(fd==-1)
        ERR_EXIT("open");
    read(fd,buf,5);
    printf("%s\n",buf);

    int fd2=dup(fd);
    printf("%d,%d\n",fd,fd2); //3 4

    read(fd2,buf,5);
    printf("%s\n",buf);

    close(fd);
    close(fd2);
    return 0;
}
