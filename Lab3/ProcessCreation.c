#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int pid = -1;

    printf("%5d %5d\n", getpid(), pid);
    exec();
    printf("%5d %5d\n", getpid(), pid);
}