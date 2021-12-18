#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/**
 * @brief Finding maximum of a, b
 * 
 * @param a 
 * @param b 
 * @return int [maximum element]
 */
int max(int a, int b)
{
    return a > b ? a : b;
}

/**
 * @brief Create a String object
 * 
 * @param size 
 *         Size of the object or string
 * @return char* 
 */
char * createString(int size)
{
    char * newstring = malloc(sizeof(char) * size);
    return newstring;
}

/**
 * @brief Returning the sizeof the string
 * 
 * @param X 
 *      X is string object / string constant
 * @return int [Size of the string]
 */
int strsize(char * X)
{
    int count = 0;
    int i = 0;
    char ch = X[i];
    while(ch != '\0')
    {
        count ++;
        ch = X[++i];
    }

    return count;
}

/**
 * @brief Finds the longest common subsequence
 * 
 * @param X  --> String A
 * @param Y  --> String B
 * @param m  --> Sizeof(A)
 * @param n  --> Sizeof(B)
 * @return char* 
 *          --> Returns the longest common subsequenced string
 */
char * lcs(char * X, char * Y, int m, int n)
{
    int L[m+1][n+1];

    for(int i = 0; i <=m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                L[i][j] = 0;

            else if(X[i-1] == Y[j - 1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    int index = L[m][n];
    char * lcs = createString(index+1);
    
    int i = m, j = n;

    while(i > 0 && j > 0)
    {
        if(X[i-1] == Y[j-1])
        {
            lcs[index-1] = X[i-1];
            i--;
            j--;
            index--;
        }
        else if(L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
    return lcs;

}

int main()
{

    char A[100];
    char B[100];

    scanf("%s", A);
    scanf("%s", B);

    char * string = lcs(A, B, strsize(A), strsize(B));
    printf("%d %s", strsize(string), string);
}