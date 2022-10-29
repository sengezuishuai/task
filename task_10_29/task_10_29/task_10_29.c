#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	int num1 = 0;
	double num2 = 0, num3 = 0, num4 = 0;
	while(1)
	{
		scanf("%d;%lf%lf%lf", &num1, &num2, &num3, &num4);
		if (num1 >= 1 && num1 <= 20000000 && num2 <= 100 && num2 >= 0 && num3 <= 100 && num3 >= 0 && num4 <= 100 && num4 >= 0)
		{
			printf("The each subject scoreof No. %d is %.2lf,%.2lf,%.2lf", num1, num2, num3, num4);
			break;
		}
		printf("输入错误请重新输入");
	}

	return 0;
}

int main()
{
	char num1;
	int i = 1, y = 0, x = 0;
	scanf("%c", &num1);
	for (i = 1; i <= 5; i++)
	{
		for (x = 5 - i; x >= 1; x--)
			printf(" ");
		for (y = 1; y <= i; y++)
			printf("%c ", num1);
		printf("\n");
	}
	return 0;
}


int main()
{
	int year = 0;
	long long e = 0;
	printf("输入");
	scanf("%lld", &year);
	e = year * 3.156e7;
	printf("%lld", e);
	return 0;
}

int main()
{
	int ID, num1,num2,num3;
	while(1)
	{
		scanf("%d", &ID);
		num1 = ID / 10000;
		num2 = ID % 1000 / 100;
		num3 = ID % 100;
		if(num1>=1990&&num1<=2015&&num2>=1&&num2<=12&&num3>=1&&num3<=30)
		{
			printf("year=%04d\nmonth=%02d\ndate=%02d", num1, num2, num3);
			break;
		}
		printf("输入错误");
	}
	return 0;
}

int main()
{
	int y, m, d;
	scanf("%4d %2d%2d", &y, &m, &d);
	printf("year=%d\n", y);
	printf("mouth=%02d\n",m);
	printf("date=%02d\n",d);
	return 0;
}
//||
int main()
{
	int i;
	int a = 0;
	long long num=0;
	while(1)
	{
		scanf("%d", &a);
		if(a>=1&&a<=1e9)
		{
			for (i = 1; i <= a; i++)
			{
				num = num + i;
			}
			printf("%lld", num);
			break;
		}
		printf("输入错误请重新输入");
	}
	return 0;
}


int main()
{
	int n, mouth;
	scanf("%d", &n);
	mouth = n / 12 * 4 + 2;
	printf("%d", mouth);
	return 0;
}

