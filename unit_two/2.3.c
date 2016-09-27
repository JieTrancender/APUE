/*************************************************************************
    > File Name: 2.3.c
    > Author: JTrancender
    > Email: jie-email@jie-trancender.org
    > Github: JieTrancender 
    > Created Time: Tue Sep 27 22:18:47 2016
 ************************************************************************/
#include "../lib/ourhdr.h"
#include <errno.h>
#include <limits.h>

#ifdef openmax
static int openmax = OPEN_MAX;
#else
static int openmax = 0;
#endif

#define OPEN_MAX_GUESS 256

int openmaxfunc()
{
	if (openmax == 0)
	{
		errno = 0;
		if ((openmax = sysconf(_SC_OPEN_MAX)) < 0)
		{
			if (0 == errno)
			{
				openmax = OPEN_MAX_GUESS;
			}
			else
			{
				err_sys("sysconf error for _SC_openmax");
			}
		}
	}
	return openmax;
}

int main()
{
	printf ("The number of max numbers that file can be opend is %d\n", openmaxfunc());
}
