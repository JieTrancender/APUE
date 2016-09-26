/*************************************************************************
    > File Name: get_pid_second.c
    > Author: JTrancender
    > Email: jie-email@jie-trancender.org
    > Github: JieTrancender 
    > Created Time: Mon Sep 26 14:38:32 2016
 ************************************************************************/
#include "./lib/ourhdr.h"
#include <sys/wait.h>
#include <sys/types.h>

int debug = 1;

int main(int argc, char **argv)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	printf("%% ");

	while (fgets(buf, MAXLINE, stdin) != NULL)
	{
		buf[strlen(buf) - 1] = 0;

		if ((pid = fork()) < 0)
		{
			err_sys("fork error");
		}
		else if (pid == 0)
		{
			execlp(buf, buf, (char *)0);
			err_ret("couldn't execute: %s", buf);
			exit(127);
		}
		if ((pid = waitpid(pid, &status, 0)) < 0)
		{
			err_sys("waitpid error");
		}
	}
	exit(0);
}
