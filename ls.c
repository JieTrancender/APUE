/*************************************************************************
    > File Name: ls.c
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Mon Sep 19 16:23:09 2016
 ************************************************************************/

#include <sys/types.h>
#include <dirent.h>
#include "ourhdr.h"

int debug = 0;

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;

	if (argc != 2)
	{
		err_quit("A single argument (the directory name) is required");
	}

	if ((dp = opendir(argv[1])) == NULL)
	{
		err_sys("Can't open %s", argv[1]);
	}

	while ((dirp = readdir(dp)) != NULL)
	{
		printf("%s\n", dirp->d_name);
	}

	closedir(dp);
	exit(0);
}
