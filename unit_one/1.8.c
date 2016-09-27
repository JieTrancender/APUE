/*************************************************************************
    > File Name: 1.8.c
    > Author: JTrancender
    > Email: jie-email@jie-trancender.org
    > Github: JieTrancender 
    > Created Time: Tue Sep 27 21:54:42 2016
 ************************************************************************/
#include "../lib/ourhdr.h"
#include <sys/types.h>
#include <signal.h>

int debug = 0;

static void sig_int(int);	//our signal-catching function

int main()
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal error");

	printf("%% ");
	while (fgets(buf, MAXLINE, stdin) != NULL)
	{
		buf[strlen(buf) - 1] = 0;

		if ((pid = fork()) < 0)
			err_sys("fork error");

		else if (pid == 0)
		{
			execlp(buf, buf, (char *)0);
			err_ret("couldn't execute: %s", buf);
			exit(127);
		}
		if ((pid = waitpid(pid, &status, 0)) < 0)
			err_sys("waitpid error");
		printf("%% ");
	}
}

void sig_int(int signo)
{
	printf("interrupt\n%% ");
}
