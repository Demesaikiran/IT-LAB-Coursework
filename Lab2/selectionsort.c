#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 32


clock_t start, end;
double cpu_time_used;

int readData(int data[], char filename[SIZE]);
void selectionSort(int data[], int n);
void printData(int data[], int n);

int main()
{
    char filename[SIZE];
    int data[1000000];
    
    printf("Enter the file name: ");
    scanf("%s", filename);

    int datalen = readData(data, filename);
    selectionSort(data, datalen);
    //printData(data, datalen);
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

void printData(int data[], int n)
{
    for(int current = 0; current < n; current++)
    {
        printf("%d  ", data[current]);
    }
    return;
}

void selectionSort(int data[], int n)
{
    int smallest, temp;

    start = clock();


    for(int current = 0; current < n; current++)
    {
        smallest = current;

        for(int i = current + 1; i <= n; i++)
        {
            if(data[i] < data[smallest])
                smallest = i;
        }

        temp           = data[current];
        data[current]  = data[smallest];
        data[smallest] = temp;
    }
    end = clock();
	
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime: %lf\nValue of n is: %d\n\n", cpu_time_used, n);

    return;
}