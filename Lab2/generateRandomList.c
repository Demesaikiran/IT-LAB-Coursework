#include<stdio.h>
#include<stdlib.h>

#define SIZE 32

int power10(int k)
{
    int prod = 1;
    while(k--)
    {
        prod *= 10;
    }
    return prod;
}

int main()
{
    system("clear");   
    char filename[SIZE];
    printf("Enter a file name to store the required numbers [<Value>_numbers.txt] : ");
    scanf("%s", filename);
    FILE *fp;
    // Opening File in write mode
    fp = fopen(filename, "w");
    if(fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    
    int k;
    printf("\nEnter the value of k for 10^k numbers to generate: ");
    scanf("%d", &k);
    int ranger = power10(k);

    for(int iter = 1; iter <= ranger; iter++)
    {
        //int num = 0;
        int num = rand() % ranger;
        fprintf(fp, "%d ", num);
    }

    fclose(fp);

    printf("\n\nGenerated numbers to the file %s successfully...\n\n", filename);
    return 0;

}