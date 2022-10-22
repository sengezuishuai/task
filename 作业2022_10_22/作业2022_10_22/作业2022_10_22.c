#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int main()
{
	int i = 0;
	int j = 0;
	float arr1[] = { 0 };
	float arr2[] = { 0 };
	float arr3[] = { 0 };
	float arr4[] = { 0 };
	float arr5[] = { 0 };
	for (i = 0; i < 5; i++)
	{
		
		scanf("%f", arr1[i]);
		if (arr1[i] < 0 && arr1[i]>100)
		{
			arr1[i] = ' ';
			printf("输入错误请重新输入");
		
		}
	}
	for (i = 0; i < 5; i++)
	{

		scanf("%f", arr2[i]);
		if (arr1[i] < 0 && arr1[i]>100)
		{
			arr2[i] = ' ';
			printf("输入错误请重新输入");

		}
	}
	for (i = 0; i < 5; i++)
	{

		scanf("%f", arr1[i]);
		if (arr3[i] < 0 && arr1[i]>100)
		{
			arr3[i] = ' ';
			printf("输入错误请重新输入");

		}
	}
	for (i = 0; i < 5; i++)
	{

		scanf("%f", arr1[i]);
		if (arr4[i] < 0 && arr1[i]>100)
		{
			arr4[i] = ' ';
			printf("输入错误请重新输入");

		}
	}
	for (i = 0; i < 5; i++)
	{

		scanf("%f", arr1[i]);
		if (arr5[i] < 0 && arr1[i]>100)
		{
			arr5[i] = ' ';
			printf("输入错误请重新输入");

		}
	}

	for (i = 0; i < 5; i++)
	{
		printf("%f ",arr1[i]);
	}
	printf("%f\n", arr1[1] + arr1[2] + arr1[3] + arr1[4] + arr1[0]);

	for (i = 0; i < 5; i++)
	{
		printf("%f ", arr1[i]);
	}
	printf("%f\n", arr2[1] + arr2[2] + arr2[3] + arr2[4] + arr2[0]);

	for (i = 0; i < 5; i++)
	{
		printf("%f ", arr1[i]);
	}
	printf("%f\n", arr3[1] + arr3[2] + arr3[3] + arr3[4] + arr3[0]);

	for (i = 0; i < 5; i++)
	{
		printf("%f ", arr1[i]);
	}
	printf("%f\n", arr4[1] + arr4[2] + arr4[3] + arr4[4] + arr4[0]);

	for (i = 0; i < 5; i++)
	{
		printf("%f ", arr1[i]);
	}
	printf("%f\n", arr5[1] + arr5[2] + arr5[3] + arr5[4] + arr5[0]);
	return 0;
}

int main()
{
	int i = 0;
	int j = 0;
	while (1)
	{
		scanf("%d", &i);
		if (i >= 1 && i <= 100)
		{
			break;
		}
		printf("输入错误，请重新输入\n");
	}
	for (j = 1; j <= i; j++)
	{
		printf("*");
	}
	return 0;
}

int main()
{
	int i = 1, k = 1;
	int arr[] = { 0 };
	printf("你要比较几个数：");
	scanf("%d", &k);
	for (i = 0; i < k-1; i++)
	{
		scanf("%d\n",&arr[i]);

	}
	for (i = 0; i < k - 1; i++)
	{
		if (arr[i] > 0)
			printf("1");
		else if (arr[i] == 0)
			printf("0.5");
		else
			printf("0");

	}


	return 0;
}

#include <stdio.h>
int main()
{
    int a[11] = { 1,2,3,4,5,7,8,9,10,11 };
    int i, t, m;
    printf("输入一个数:\n");
    scanf("%d", &m);
    for (i = 0; i < 11; i++)
    {
        if (m < a[i])
        {
            t = m; m = a[i]; a[i] = t;
        }
        else if (m > a[9])
            a[10] = m;
    }
    printf("排序后:\n");
    for (i = 0; i < 11; i++)
        printf("%d ", a[i]);
    return 0;
}

#include<stdio.h>
int main()
{
    int a[100][100], i, j, num;
    printf("请输入需要打印的行数：");
    scanf("%d", &num);
    for (i = 0; i < 100; i++)                            
    {    
        for (j = 0; j < 100; j++)
            a[i][j] = 0;
    }
    for (i = 0; i < num; i++)                                
        a[i][0] = 1;
    for (i = 1; i < num; i++)                              
        for (j = 1; j <= i; j++)
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
    for (i = 0; i < num; i++)                                 
    {
        for (j = 0; j <= i; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}

int main()
{
	int i = 0,o=0,p=0,l=0;
	scanf("%d", &i);
	while (1)
	{
		if (i >= 0 && i < 100000000)
		{
			break;
		}
		printf("输入错误请重新输入\n");
	}
	printf("%d ", i / 3600);
	o = i % 3600;
	printf("%d ", o / 60);
	p = o % 60;
	printf("%d ", p);
}