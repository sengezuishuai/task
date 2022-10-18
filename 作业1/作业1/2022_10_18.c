#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int main()
//{
//	char c1 = 'C', c2 = 'h', c3 = 'i', c4 = 'n', c5 = 'a';
//	c1 += 4; c2 += 4; c3 += 4; c4 += 4; c5 += 4;
//	//putchar（）只能用一个字符但它可以起到清理字符的作用
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
	printf("请输入圆柱的半径与高");
	scanf("%f%f", &r, &h);
	printf("圆周长是%.2f\n", 3.14*2*r);
	printf("圆面积是%.2f\n", 3.14*r*r);
	printf("圆球表面积是%.2f\n", 4*3.14*r*r);
	printf("圆球体积是%.2f\n", 4/3*3.14*r*r*r);
	printf("圆柱体体积是%.2f\n", 3.14*r*r*h);
	return 0;
}