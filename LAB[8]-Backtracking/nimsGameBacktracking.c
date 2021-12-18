#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

int min(int a, int b)
{
    return a < b ? a: b;
}

int nimsGame(int i, int j)
{
    if(i == j) return TRUE;

    for(int k = 1; k < j; k++)
    {
        if(!nimsGame(i - k, min(2 * k, i - k)))
            return TRUE;
    }

    return FALSE;
}


int main()
{
    int n,m;
    scanf("%d%d", &n, &m);

    printf("%d", nimsGame(n, m));
}