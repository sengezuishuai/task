#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int main()
//{
//	char c1 = 'C', c2 = 'h', c3 = 'i', c4 = 'n', c5 = 'a';
//	c1 += 4; c2 += 4; c3 += 4; c4 += 4; c5 += 4;
//	//putchar����ֻ����һ���ַ����������������ַ�������
//	putchar(c1);
//	putchar(c2);
//	putchar(c3);
//	putchar(c4);
//	putchar(c5);
//	printf("%c%c%c%c%c", c1, c2, c3, c4, c5);
//	return 0;
//}

int main()
{
	float r = 1.5, h = 3.0;
	printf("������Բ���İ뾶���");
	scanf("%f%f", &r, &h);
	printf("Բ�ܳ���%.2f\n", 3.14*2*r);
	printf("Բ�����%.2f\n", 3.14*r*r);
	printf("Բ��������%.2f\n", 4*3.14*r*r);
	printf("Բ�������%.2f\n", 4/3*3.14*r*r*r);
	printf("Բ���������%.2f\n", 3.14*r*r*h);
	return 0;
}