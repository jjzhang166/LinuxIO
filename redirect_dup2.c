/*************************************************************************
	> File Name: redirect_dup2.c
	> Author: xuxiaoqiang
	> Mail:353271054@qq.com 
	> Created Time: 2014年07月23日 星期三 21时31分43秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<errno.h>

#define ERR_EXIT(m)\
    do{\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
int main(int argc, const char *argv[])
{
    
    int fd=open("test.txt",O_RDONLY,0666);
    if(fd==-1)
        ERR_EXIT("open");
    //stdin -> test.txt
    //将标准输入重定向到test.txt
    //采用dup2的方式

    dup2(fd,STDIN_FILENO);
    
    char buf[100];
    fgets(buf,100,stdin);

    fputs(buf,stdout);
    close(fd);
    return 0;
}
