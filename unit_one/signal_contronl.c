/*************************************************************************
	> File Name: signal_contronl.c
	> Author: 
	> Mail: 
	> Created Time: Tue Nov  1 11:48:28 2016
 ************************************************************************/

#include "../lib/apue.h"
#include <sys/wait.h>

static void sig_int(int);  //our signal-catching function

int main(int argc, char* argv[])
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if (signal(SIGNAL, sig_int) == SIG_ERR)
    {
        err_sys("signal error");
    }

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] = '\n')
        {
            buf[strlen(buf) - 1] = 0;
        }

        if ((pid = fork()) < 0)
        {
            err_sys("fork error");
        }
        else if (pid == 0)
        {
            execlp(buf, buf, (char *)0);
            err_sys("Cant exec %s", buf);
            exit(1);
        }

    }
}
