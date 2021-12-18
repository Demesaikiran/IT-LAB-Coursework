#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


int * createArray(int size)
{
    int * array = malloc(sizeof(int) * size);

    return array;
}

void printOrder(int i, int j, int n, int count, int * mat)
{
    int k = *((mat + j * n) + i);
    if(i < j)
    {
        printf("(%d",i);
        count++;
        printOrder(i, k, n, count, (int *) mat);
        printOrder(k+1, j, n, count, (int *) mat);
        if(count == n-2)
            printf("%d)", j);
        else
            printf(")");
    }
}


int matrixChainDP(int * dim, int nOfMat)
{
    int multi[nOfMat+1][nOfMat+1];
    int j,k;

    for(int i = 1; i <= nOfMat; i++)
    {
        multi[i][i] = 0;
    }

    for(int l = 2; l <= nOfMat; ++l)
    {
        for(int i = 1; i + l <= nOfMat + 1; ++i)
        {
            j = i + l - 1;
            k = i;
            multi[j][i] = k;
            int temp = multi[i][k] + multi[k+1][j]+dim[i-1] * dim[k] * dim[j];
            multi[i][j] = INT_MAX;

            for(k = i; k < j; ++k)
            {
                if(multi[i][j] >temp)
                {
                    multi[i][j] = temp;
                    multi[j][i] = k;
                }
            }
        }
    }

    printf("%d", multi[1][nOfMat]);

    printOrder(1, nOfMat,nOfMat+1, 0, (int *) multi);
    return multi[1][nOfMat];
}

int main()
{
    int n;
    scanf("%d", &n);

    int * arr = createArray(n+1);

    for (int i = 0; i <= n; i++)
        scanf("%d", &arr[i]);

    int nOfCalculations = matrixChainDP(arr, n);
    printf("%d", nOfCalculations);
}