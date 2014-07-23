/*************************************************************************
	> File Name: fcntl_dup.c
	> Author: xuxiaoqiang
	> Mail:353271054@qq.com 
	> Created Time: 2014年07月23日 星期三 20时14分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
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
    int readn;
    int fd=open("test.txt",O_RDONLY);
    if(fd==-1)
        ERR_EXIT("open");
    readn=read(fd,buf,5);
    printf("%s\n",buf);

    //复制文件描述符
    //
    //可以发现吃用复制后的文件描述符后文文件的偏移量是相同的。
    int fd2=fcntl(fd,F_DUPFD,0);
    readn=read(fd2,buf,5);
    printf("%s\n",buf);

    close(fd);
    close(fd2);
    return 0;
}
