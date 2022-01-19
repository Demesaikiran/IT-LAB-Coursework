#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/**
 * @brief Create a Array object
 * 
 * @param size <Size of the array>
 * @return int* 
 */
int * createArray(int size)
{
    int * array = malloc(sizeof(int) * size);

    return array;
}

/**
 * @brief Matric chain multiplication problem
 *          Minimising the number of matrix multiplications
 *          Using Resursive method
 * @param dim <Dimensions of the matrices...>
 * @param i 
 * @param j 
 * @return int <Returns the total number of minimum multiplications>
 */
int MatrixChainRecursive(int* dim, int i, int j)
{
    if(i == j) return 0;

    int minCount = INT_MAX;

    int k;
    for(int k = i; k < j; k++)
    {
        int count = MatrixChainRecursive(dim, i, k) + MatrixChainRecursive(dim, k+1, j)+
                dim[i-1] * dim[k] * dim[j];
        
        if(count < minCount) minCount = count;
    }

    return minCount;
}

int main()
{
    int n;
    scanf("%d", &n);

    int * arr = createArray(n);

    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int nOfCalculations = MatrixChainRecursive(arr, 1, n);
    printf("%d", nOfCalculations);
    
}