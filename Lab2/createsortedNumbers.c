#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 32


clock_t start, end;
double cpu_time_used;

int readData(int data[], char filename[SIZE]);
void insertionSort(int data[], int n);
void createSortedFile(int data[], int n);

int main()
{
    char filename[SIZE];
    int data[1000000];
    
    printf("Enter the file name: ");
    scanf("%s", filename);

    int datalen = readData(data, filename);
    insertionSort(data, datalen);
    createSortedFile(data, datalen);


}

int readData(int data[], char filename[SIZE])
{
    int N = 0;
    FILE *fp = NULL;

    fp = fopen(filename, "r");

    if( fp == NULL )
    {
        printf("\nError in opening the file %s", filename);
        exit(1);
    }

    while(fscanf(fp, "%d", &data[N]) != EOF)
    {
        N++;
    }

    fclose(fp);
    return N;
}

void createSortedFile(int data[], int n)
{
    char filename[SIZE];
    printf("Enter a file name to store the required sorted numbers[<Value>_numbers_sorted.txt] : ");
    scanf("%s", filename);
    FILE *fp;
    fp = fopen(filename, "w");
    if(fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    int choice;
    printf("\n\nEnter choice of sorting\n======================\n1. Sorted order file\n2. Reversely Sorted file\n\nEnter your choice[1/2]: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        for(int i = 0; i < n; i++)
        {
            fprintf(fp, "%d ", data[i]);
        }
        break;
    case 2:
        for(int i = n-1; i >= 0; i--)
        {
            fprintf(fp, "%d ", data[i]);
        }
        break;    
    default:
        break;
    }
    
    fclose(fp);
    printf("\n\nYour file %s generated Successfully...\n\n", filename);
    return;
}

void insertionSort(int data[], int n)
{
    int temp, trace;
    int locate;


    for(int current = 1; current <= n; current++)
    {
        locate = 0;
        temp = data[current];
        for(trace = current -1; trace >= 0 && !locate; )
        {
            if(temp < data[trace])
            {
                data[trace + 1] = data[trace];
                trace --;
            }
            else
                locate = 1;

        }
        data[trace + 1] = temp;
    }
    
    return;
}
