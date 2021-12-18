#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(int a, int b) { return a < b ? a : b; }

int findMinInsertions(char str[], int n)
{
    int table[n][n], l, h, gap;

    memset(table, 0, sizeof(table));

    for(gap = 1; gap < n; ++gap)
    {
        for(l = 0, h = gap; h < n; ++l, ++h)
        {
            table[l][h] = str[1] == str[h] ? table[l+1][h-1] : (min(table[l][h-1], table[l+1][h]) + 1);
        }
    }

    return table[0][n-1];
}

int main()
{
    char s[] = "aab";
    printf("%d", findMinInsertions(s, 3));
    return 0;
}