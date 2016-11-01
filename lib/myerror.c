/*************************************************************************
    > File Name: myerror.c
    > Author: Jie Mo
    > Email: 582865471@vip.qq.com 
    > Github: JieTrancender 
    > Created Time: Mon Sep 19 15:32:57 2016
 ************************************************************************/

#include <errno.h>
#include <stdarg.h>
#include <syslog.h>
#include "apue.h"

static void err_doit(int, const char *, va_list);
static void log_doit(int, int, const char *, va_list ap);

char *pname = NULL;	//caller can set this form argv[0]

//Nonfatal error related to a system call.
//Print a message and return.
void err_ret(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, fmt, ap);
	va_end(ap);
	return;
}

//Fatal error related to a system call.
//Print a message and terminate.
void err_sys(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, fmt, ap);
	va_end(ap);
	exit(1);
}

//Fatal error related to a system call.
//Print a message, dump core, and terminate.
void err_dump(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, fmt, ap);
	va_end(ap);
	abort();
	exit(1);
}

//Nonfatal error unrelated to a system call.
//Print a message and return.
void err_msg(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	err_doit(0, fmt, ap);
	va_end(ap);
	return;
}

//Fatal error unrelated to a system call.
//Print a message and terminate.
void err_quit(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	err_doit(0, fmt, ap);
	va_end(ap);
	exit(1);
}

//Print a message and return to caller.
//Caller specifies "errnoflag."
static void err_doit(int errnoflag, const char *fmt, va_list ap)
{
	int errno_save;
	char buf[MAXLINE];

	errno_save = errno;	//value caller might want to print
	vsprintf(buf, fmt, ap);	//use vsprintf when the third argument is va_list, and use sprintf when not
	if (errnoflag)
	{
		sprintf(buf + strlen(buf), ": %s", strerror(errno_save));
	}
	strcat(buf, "\n");
	fflush(stdout);	//in case stdout and stderr are the same
	fputs(buf, stderr);
	fflush(NULL);	//flushes all stdio output streams
	return;
}

/*extern int debug;	//caller must define and set this: nonzero if interactive, zero if daemon

//Initialize syslog(), if running as daemon
void log_open(const char *ident, int option, int facility)
{
	if (0 == debug)
		openlog(ident, option, facility);
}

//Nonfatal error related to a system call.
//Print a message with the system's errno value and return.
void log_ret(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	log_doit(1, LOG_ERR, fmt, ap);
	va_end(ap);
	return;
}

//Fatal error related to a system call.
//Print a message and terminate.
void log_sys(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	log_doit(1, LOG_ERR, fmt, ap);
	va_end(ap);
	exit(2);
}

//Nonfatal error unrelated to a system call.
//Print a message and return.
void log_msg(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	log_doit(0, LOG_ERR, fmt, ap);
	va_end(ap);
	return;
}

//Fatal error unrelated to a system call.
//Print a message and terminate.
void log_quit(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	log_doit(0, LOG_ERR, fmt, ap);
	va_end(ap);
	exit(2);
}

//Print a message and return to caller.
//Caller specifies "errnoflag" and "priority".
static void log_doit(int errnoflag, int priority, const char *fmt, va_list ap)
{
	int errno_save;
	char buf[MAXLINE];

	errno_save = errno;
	vsprintf(buf, fmt, ap);
	if (errnoflag)
		sprintf(buf + strlen(buf), ": %s", strerror(errno_save));
	strcat(buf, "\n");
	if (debug)
	{
		fflush(stdout);
		fputs(buf, stderr);
		fflush(stderr);
	}
	else
	{
		syslog(priority, buf);
	}
	return;
}*/
