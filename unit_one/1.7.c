/*************************************************************************
    > File Name: 1.7.c
    > Author: JTrancender
    > Email: jie-email@jie-trancender.org
    > Github: JieTrancender 
    > Created Time: Tue Sep 27 21:51:09 2016
 ************************************************************************/
#include "../lib/ourhdr.h"

int debug = 0;

int main(int argc, char **argv)
{
	printf("uid = %d, gid = %d\n", getuid(), getgid());
}
