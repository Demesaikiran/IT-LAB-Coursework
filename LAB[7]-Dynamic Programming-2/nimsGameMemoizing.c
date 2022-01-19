#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
// #define UNKNOWN 0
// #define KNOWN 1
#define MAXSIZE 100
int Game[MAXSIZE][MAXSIZE];
int K[MAXSIZE][MAXSIZE];

int min(int a, int b)
{
    return a > b ? b : a;
}


int nims(int n, int m)
{
    if (n == m) return TRUE;

    if(K[n][m]) return Game[n][m];
    K[n][m] = TRUE;

    // if(Game[n][m] != UNKNOWN) return Game[n][m];
    
    for(int k = 1; k < m; k++)
    {
        if(!nims(n - k, min(2 * k, n - k)))
        {
            Game[n][m] = TRUE;
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
    K[0][0] = TRUE;
    for(int i = 1; i < n; i++)
        for(int j = 1; j < i; j++)
            K[i][j] = FALSE;
    nims(n, m) == FALSE ? printf("0") : printf("1");
    return 0;
}
