/*************************************************************************
	> File Name: err_func.c
	> Author: 
	> Mail: 
	> Created Time: Tue Nov  1 11:31:30 2016
 ************************************************************************/

#include "../lib/apue.h"
#include <errno.h>

int main(int argc, char* argv[])
{
    //#include <string.h>
    //char *strerror(int errno);
    //strerror func 通常将errno值映射为一个出错消息字符串
    
    //#include <stdio.h>
    //void perror(const char *msg)
    //perror func 输出msg指向的字符串，并已当前的error值映射出错消息
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);

    exit(0);
}
