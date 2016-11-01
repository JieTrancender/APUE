/*************************************************************************
	> File Name: uid_gid.c
	> Author: 
	> Mail: 
	> Created Time: Tue Nov  1 11:46:11 2016
 ************************************************************************/

#include "../lib/apue.h"

int main(int argc, char* argv[])
{
    printf("uid = %d, gid = %d\n", getuid(), getpid());

    exit(0);
}
