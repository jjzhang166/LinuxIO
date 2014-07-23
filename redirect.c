/*************************************************************************
	> File Name: redirect.c
	> Author: xuxiaoqiang
	> Mail:353271054@qq.com 
	> Created Time: 2014年07月23日 星期三 21时14分02秒
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
    int fd=open("test.txt",O_RDONLY,06666);
    if(fd==-1)
        ERR_EXIT("open");
    //stdin -> test.txt
    
    close(STDIN_FILENO);//将标准输入的文件描述符关闭
    int ret=dup(fd);//执行完这一行，0和3 都指向打开test.txt的文件表项
    
    printf("yanzhen=%d\n",ret);//如果不出意外的情况下ret的值为0

    char buf[100];
    fgets(buf,100,stdin);//此时的标准输入stdin已经重定向为test.txt

    fputs(buf,stdout);
    
    close(fd);
    return 0;
}
