#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<math.h>

clock_t start, stop;
double duration;
#define MAXN 10
double f1(int n, double a[], double x);
double f2(int n, double a[], double x);


int main()
{
	int i;
	double a[MAXN];
	for (i = 0; i < MAXN; i++)
		a[i] = (double)i;
	start = clock();
	f1(MAXN - 1, a, 1.1); 
	stop = clock;
	duration = ((double)(stop - start)) / CLK_TCK;
	printf("ticks1=%f\n", (double)(stop - start));
	printf("duration=%6.2e\n", duration);

	start = clock();
	f2(MAXN - 1, a, 1.1);
	stop = clock;
	duration = ((double)(stop - start)) / CLK_TCK;
	printf("ticks1=%f\n", (double)(stop - start));
	printf("duration=%6.2e\n", duration);

	return 0;
}