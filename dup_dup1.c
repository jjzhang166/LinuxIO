/*************************************************************************
	> File Name: dup_dup1.c
	> Author: xuxiaoqiang
	> Mail:353271054@qq.com 
	> Created Time: 2014年07月23日 星期三 20时55分30秒
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
    char buf[100]={0};
    int fd=open("test.txt",O_RDONLY);

    if(fd==-1)
        ERR_EXIT("open");
    int fd2=5;
    //dup2可以手工指定复制后的fd
    //如果fd已经占用，那么先关闭
    read(fd,buf,5);
    printf("%s\n",buf);

    dup2(fd,fd2);
    printf("fd=%d,fd2=%d\n",fd,fd2);

    read(fd2,buf,5);
    printf("%s\n",buf);
    close(fd);
    close(fd2);
    return 0;
}
