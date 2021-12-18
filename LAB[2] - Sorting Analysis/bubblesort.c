#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 32


clock_t start, end;
double cpu_time_used;

int readData(int data[], char filename[SIZE]);
void bubblesort(int data[], int n);
void printData(int data[], int n);

int main()
{
    char filename[SIZE];
    int data[1000000];
    
    printf("Enter the file name: ");
    scanf("%s", filename);

    int datalen = readData(data, filename);
    bubblesort(data, datalen);
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

void bubblesort(int data[], int n)
{
    int temp;

    start = clock();

    for(int current = 0; current < n; current++)
    {
        for (int walker = n; walker > current; walker--)
        {
            if(data[walker] < data[walker -1])
            {
                temp            = data[walker];
                data[walker]    = data[walker - 1];
                data[walker - 1]= temp;
            }
        }
        
    }
    end = clock();
	
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime: %lf\nValue of n is: %d\n\n", cpu_time_used, n);
    return;
}