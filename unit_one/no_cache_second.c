/*************************************************************************
    > File Name: no_cache_second.c
    > Author: JTrancender
    > Email: jie-email@jie-trancender.org
    > Github: JieTrancender 
    > Created Time: Mon Sep 26 14:31:08 2016
 ************************************************************************/
#include "./lib/ourhdr.h"

int debug = 0;

int main(int argc, char **argv)
{
	int c;
	while ((c = getc(stdin)) != EOF)
	{
		if (putc(c, stdout) == EOF)
		{
			err_sys("output error");
		}
	}

	if (ferror(stdin))
	{
		err_sys("input error");
	}

	exit(0);
}
