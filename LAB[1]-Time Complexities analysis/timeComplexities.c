#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<stdint.h>

clock_t start, end;
double cpu_time_used;


void logn()
{
	double n = 1000000000000000000;
	start = clock();
	for(double i = 1000000000000000000; i > 0; i /= 2)
	{ }
	end = clock();
	
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime: %lf\nValue of n is: %lf\n\n", cpu_time_used, n);

	
}

void timeN()
{	
	double n = 328000000;
	start = clock();
	for(double i = 0; i < n; i++)
	{}
	
	end = clock();
	
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime: %lf\nValue of n is: %lf\n\n", cpu_time_used, n);
}

void timeNS()
{
	double n = 18115;
	start = clock();
	for(double i = 0; i < n; i++)
		for(double j = 0; j < n; j++)
		{}
	end = clock();
	
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime: %lf\nValue of n is: %lf\n\n", cpu_time_used, n);
}

void timeNC()
{
	double n = 700;
	start = clock();
	for(double i = 0; i < n; i++)
		for(double j = 0; j < n; j++)
			for(double k = 0; k < n; k++)
		 	{}
	end = clock();
	
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime: %lf\nValue of n is: %lf\n\n", cpu_time_used, n);
}

void timeExp()
{
	double n = 28.28;
	double n1 = pow(2, n);
	start = clock();
	
	for(double i = 0; i < n1; i++)
	{}
	
	end = clock();
	
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime: %lf\nValue of n is: %lf\n\n", cpu_time_used, n);
}

void timeNF()
{
	double n = 133;
	start = clock();
	for(double i = 0; i < n; i++)
		for(double j = 0; j < n; j++)
			for(double k = 0; k < n; k++)
				for(double h = 0; h < n; h++)
		 		{}
	end = clock();
	
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime: %lf\nValue of n is: %lf\n\n", cpu_time_used, n);
}
	
void timenLogN()
{
	double n = 114500;
	
	start = clock();
	for(double i = 0; i < n; i++)
		for(double j = n; j > 0; j/= 2)
		{}
	end = clock();
	
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime: %lf\nValue of n is: %lf\n\n", cpu_time_used, n);
}
		
int main(void)
{
	system("clear");
	int n;
	
	while(1)
	{
		printf("Below are the complexities you can test\n==========================================\n1. O(log n)\n2. O(n)\n3. O(n^2)\n4. O(n^3)\n5. O(2^n)\n6. O(n^4)\n7. O(n logn)\n8. End the program\n\nEnter your choice to test: ");
		scanf("%d", &n);
		
		switch(n)
		{
			case 1: logn();
				break;
			case 2: timeN();
				break;
			case 3: timeNS();
				break;
			case 4: timeNC();
				break;
			case 5: timeExp();
				break;
			case 6: timeNF();
				break;
			case 7: timenLogN();
				break;
			default: return 0;
		}
	}
	
	return 0;
}
	
	
	
	
