/*************************************************************************
	> File Name: strftime_test.cpp
	> Author: Jason
	> Mail: jie-email@jie-trancender.org
	> Created Time: 2017年03月27日 星期一 14时37分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
    time_t t;
    struct tm *tmp;
    char buf1[16];
    char buf2[128];

    time(&t);
    tmp = localtime(&t);
    if (strftime(buf1, 16, "time and date: %r, %a %b %d, %Y", tmp) == 0)
    {
        printf("buffer length 16 is too small\n");
    }
    else
    {
        printf("%s\n", buf1);
    }
    
    if (strftime(buf2, 16, "time and date: %r, %a %b %d, %Y", tmp) == 0)
    {
        printf("buffer length 128 is too small\n");
    }
    else
    {
        printf("%s\n", buf2);
    }
    return 0;
}
