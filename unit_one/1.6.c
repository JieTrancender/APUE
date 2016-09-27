/*************************************************************************
    > File Name: 1.6.c
    > Author: JTrancender
    > Email: jie-email@jie-trancender.org
    > Github: JieTrancender 
    > Created Time: Tue Sep 27 21:47:06 2016
 ************************************************************************/

#include "../lib/ourhdr.h"
#include <errno.h>

int debug = 0;

int main(int argc, char **argv)
{
	fprintf(stderr, "EACCES: %s\n", strerror(EACCES));

	errno = ENOENT;
	perror(argv[0]);

	exit(0);
}
