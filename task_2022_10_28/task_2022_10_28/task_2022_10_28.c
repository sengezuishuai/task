#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>//sqrt()是求平方根函数

int main()
{
	int x;
	scanf("%d", &x);
	if (x < 1)
		printf("%d", x);
	if (x >= 1 && x < 10)
		printf("%d", 2 * x - 1);
	if (x > 10)
		printf("%d", 3 * x - 11);

}


int main()
{
	int x, i;
	scanf("%d", &x);
	if (0 < x && 1000 >= x)
	{
		i = sqrt(x);
	}
	else
		printf("数据不符合要求。");
	return  0;
}

int main()
{
	int x, i;
	scanf("%d", &x);
	if (x == 100)
	{
		printf("A");
	}
	i = x / 10;
	switch(i)
{
	case 9:
	{
		printf("A");
		break;
	}
	case 8:
	{
		printf("B");
		break;
	}
	case 7:
	{
		printf("C");
		break;
	}
	case 6:
	{
		printf("D");
		break;
	}
	case 5:
	case 4:
	case 3:
	case 2:
	case 1:
	case 0:
	{
		printf("E");
		break;
	}
}
	if (x > 100 || x < 0)
		printf("输入数据错，程序结束");
	return 0;
}

int main()
{
	int a, b, c, d, i;
	for(a=100;a<1000;a++)
	{
		b = a / 100;
		c = a % 100 / 10;
		d = a % 10;
		if (b* b* b + c * c * c + d * d * d == a)
			printf("%d ",a);
	}
	return 0;
}

int main()
{
	int i = 10, b = 1;
	//scanf("%d", &i);//可以变成常规化问题
	for (i = 10; i > 0; i--)
	{
		b = (b + 1) * 2;
	}
	printf("%d", b);
	return 0;
}




int main()
{
	int i, q, z = 20, n = 1, sum = 0;
	//scanf("%d", &z);//普遍情况
	for (i = 1; i < z; i++)
	{
		for (q = 1; q < i; q++)
		{
			n = n * i * q;
		}
		sum = n + sum;
	}
	printf("%d", sum);
	return 0;
}