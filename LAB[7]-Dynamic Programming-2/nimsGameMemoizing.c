#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE -1
#define UNKNOWN 0
#define MAXSIZE 100
int Game[MAXSIZE][MAXSIZE];

int min(int a, int b)
{
    return a > b ? b : a;
}


int nims(int n, int m)
{
    if(Game[n][m] != UNKNOWN) return Game[n][m];
    
    for(int k = 1; k < m; k++)
    {
        if(!nims(n - k, min(2 * k, n - k)))
        {
            Game[n][k] = TRUE;
            return TRUE;
        }
    }
    Game[n][m] = FALSE;
    return FALSE;
}

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d%d", &n, &m);
    nims(n, m) == -1 ? printf("0") : printf("1");
    return 0;
}
