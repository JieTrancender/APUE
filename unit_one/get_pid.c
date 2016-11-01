/*************************************************************************
    > File Name: get_pid.c
    > Author: JTrancender
    > Email: jie-email@jie-trancender.org
    > Github: JieTrancender 
    > Created Time: Mon Sep 26 14:36:06 2016
 ************************************************************************/
#include "./lib/ourhdr.h"

int debug = 0;

int main(int argc, char **argv)
{
	printf("Hello world from process ID %d\n", getpid());
	exit(0);
}
