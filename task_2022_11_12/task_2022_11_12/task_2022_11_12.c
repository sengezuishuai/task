#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//int main()
//{
//	int arr[] = { 1,2,(3,4),5 };
//	printf("%d\n", sizeof(arr));
//	return 0;
//}

//int main()
//{
//	char str[] = "hello bit";
//	printf("%d %d", sizeof(str), sizeof(str));
//	return 0;
//}

//int main()
//{
//	int a[2][] = { {0,1,2},{3,4,5} };
//	int a[][3] = { {0,1,2} ,{3,4,5} };
//}

//int main()
//{
//	char arr[] = "asdf";
//	char arr1[] = { 'a','s','d','f' };
//	printf("%d", sizeof(arr1));
//}

//#include<stdio.h>
//
//int main()
//
//{
//    int i, j, k;
//
//    int A[10];
//
//    int B[10];
//
//    int C[10];
//
//    printf("������A��������ݣ�\n");
//
//    for (i = 0; i < 10; i++)
//
//    {
//        scanf("%d", &A[i]);
//    }
//
//    printf("������B��������ݣ�\n");
//
//    for (j = 0; j < 10; j++)
//
//    {
//        scanf("%d", &B[j]);
//    }
//
//    for (k = 0; k < 10; k++)
//
//    {
//        A[k] = A[k] ^ B[k];      
//
//        B[k] = A[k] ^ B[k];     
//
//        A[k] = A[k] ^ B[k];                     B[k] = A[k] - B[k];
//
//    }                                           A[k] = A[k] - B[k];
//
//
//
//    printf("�������A����Ϊ:\n");
//
//    for (i = 0; i < 10; i++)
//
//    {
//        printf("%d ", A[i]);
//    }
//
//    printf("\n");
//
//    printf("�������B����Ϊ:\n");
//
//    for (j = 0; j < 10; j++)
//
//    {
//        printf("%d ", B[j]);
//    }
//
//    printf("\n");
//
//    return 0;
//
//}



//void init(int(*p)[] ,int ret)
//{
//	int i = 0;
//	for (; i < ret; i++)
//	{
//		p[i] = { 0 };
//	}
//}
//
//int main()
//{
//	int arr[10];
//	init(arr, sizeof(arr) / sizeof(arr[0]));
//}

//#include<stdio.h>
//#include<string.h>
//#define M 5   
//#define N 20
//void s][N] = { 0 };
//    int i;
//    printf("please input %d character strings:\n", M);
//    for (i = 0; i < M; i++)
//    {
//        scanf("%s", a[i]);//�˴�����д��*a++����Ϊa��һ�����������Ǳ����������ƶ�����
//    }
//    sort(a);
//    printf("after sorting,the sequence is :\n");
//    for (i = 0; i < M; i++)
//    {
//        printf("%s\n", a[i]);//�˴�Ҳͬ�ϣ�����ʹ��*a++��һ������
//    }
//    return 0;
//}
//void sort(char(*p)[N])
//{
//    int i, j;
//    char temp[N] = { 0 };
//    for (i = 0; i < M - 1ort(char(*p)[N]);
//int main()
//{
//    char a[M; i++)    //ѡ������
//    {
//        for (j = i + 1; j < M; j++)
//        {
//            if (strcmp(p[i], p[j]) > 0)
//            {
//                strcpy(temp, p[i]);//��strcpy�����Ĵ����������ƣ��˴�ֻ��дp[i],������p+i
//                strcpy(p[i], p[j]);//p[i]��������char *����p+i��������char (*p)[N]
//                strcpy(p[j], temp);//���ܺ�ʱ��һ��һ��ע���������͵�ƥ��
//            }
//        }
//    }
//}


void Init(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		arr[i] = 2;
	}
}

//void print(int arr[], int sz)
//{
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//void reverse(int a[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int b;
//	while (left < right)
//	{
//		b = a[right];
//		a[right] = a[left];
//		a[left] = b;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	Init(a, sz);
//	reverse(a, sz);
//	print(a, sz);
//	return 0;
//}

//feibonaqi(int i)
//{
//	long long a = 0;
//	if (i < 3)
//		a = 1;
//	else
//	{
//		a = feibonaqi(i - 1) + feibonaqi(i - 2);
//	}
//	return a;
//}
//
//
//
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	long long i=feibonaqi(a);
//	printf("%lld", i);
//}

//#include <stdio.h>
//int F(int n)
//{
//	if (n == 0) 
//		return 0;
//	if (n == 1 || n == 2)
//		return 1;
//	return F(n - 1) + F(n - 2);
//}
//
//int main()
//{
//	int n;
//		scanf("%d", &n);
//		printf("%d\n", F(n));
//	return 0;
//}

//long long feibonaqi(int a)
//{
//	int b, c, i;
//	long long d = 1;
//	b = 1, c = 1;
//	if (a < 3)
//		;
//	else
//	{
//		for (i = 3; i < a; i++)
//		{
//			d = b + c;
//			b = b + c;
//			c = b;
//		}
//	}
//	return d;
//}
//
//
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	long long i=feibonaqi(a);
//	printf("%lld", i);
//}

//int jiechen(int j)
{
	int a = 0;
	if (j > 0)
	{
		a = jiechen(j) * jiechen(j - 1);
	}
	return j;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	int f = jiechen(a);
	printf("%d", f);
}
//{
//	int a = 0;
//	if (j > 0)
//	{
//		a = jiechen(j) * jiechen(j - 1);
//	}
//	return j;
//}

int main()
{
	int a = 0;
	scanf("%d", &a);
	int f = jiechen(a);
	printf("%d", f);
}

#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int fact = 1;
	int i;
	for (i = 1; i <= n; i++)
	{
		fact *= i;
	}
	printf("%d\n", fact);
	return 0;
}
