/*************************************************************************
    > File Name: no_cache.c
    > Author: JTrancender
    > Email: jie-email@jie-trancender.org
    > Github: JieTrancender 
    > Created Time: Mon Sep 19 18:51:09 2016
 ************************************************************************/

#include "./lib/ourhdr.h"

#define BUFFSIZE 8192

int debug = 0;

int main(int argc, char *argv[])
{
	int n;
	char buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
	{
		if (write(STDOUT_FILENO, buf, n) != n)
		{
			err_sys("write error");
		}
	}

	if (n < 0)
	{
		err_sys("read error");
	}
	exit(0);
}
