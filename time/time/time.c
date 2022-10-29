#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>
#include<string.h>

编程中经常用到时间表达及转换的函数，它们都定义在time.h库函数中，在此做一下总结，以方便后续查看使用。

几个时间概念：
1：Coordinated Universal Time(UTC)：
协调世界时，又称世界标准时间，也即格林威治标准时间(Greenwich Mean Time, GMT)，中国内地的时间与UTC得时差为 + 8，也即UTC + 8，美国为UTC - 5。

2：Calendar Time：
日历时间，是用“从一个标准时间点到此时的时间经过的秒数”来表示的时间。标准时间点对不同编译器可能会不同，但对一个编译系统来说，标准时间是不变的。一般是表示距离UTC时间 1970 - 01 - 01 00:00 : 00的秒数。
3：epoch：
时间点。在标准c / c++中是一个整数，用此时的时间和标准时间点相差的秒数（即日历时间）来表示。
4：clock tick：
时钟计时单元（而不叫做时钟滴答次数），一个时钟计时单元的时间长短是由cpu控制的，一个clock tick不是cpu的一个时钟周期，而是c / c++的一个基本计时单位。

time.h的定义
time.h 头文件定义了四个变量类型、两个宏和各种操作日期和时间的函数。

4个变量
size_t	是无符号整数类型，它是 sizeof 关键字的结果。
clock_t	这是一个适合存储处理器时间的类型，类型为unsigned long
time_t	这是一个适合存储日历时间类型。
struct tm	这是一个用来保存时间和日期的结构。
	
tm 结构的定义如下：
struct tm
{
	int tm_sec;         /* 秒，范围从 0 到 59      */
	int tm_min;         /* 分，范围从 0 到 59      */
	int tm_hour;        /* 小时，范围从 0 到 23     */
	int tm_mday;        /* 一月中的第几天，范围从 1 到 31    */
	int tm_mon;         /* 月，范围从 0 到 11(注意)  */
	int tm_year;        /* 自 1900 年起的年数      */
	int tm_wday;        /* 一周中的第几天，范围从 0 到 6 */
	int tm_yday;        /* 一年中的第几天，范围从 0 到 365   */
	int tm_isdst;       /* 夏令时               */
};

两个宏
NULL	这个宏是一个空指针常量的值。
CLOCKS_PER_SEC	这个宏表示每秒的处理器时钟个数。用于将clock()函数的结果转化为以秒为单位的量，
这个量的具体值是与操作系统相关的，通常为1000。

库函数
1：clock函数
函数原型：   clock_t clock(void)
函数返回：返回clock函数执行起（一般为程序的开头），处理器时钟所使用的时间。
函数功能：用来计算程序或程序的某一段的执行时间。

#include<stdio.h>
#include<time.h>

int main()
{
    clock_t start_t, finish_t;
    double total_t = 0;
    int i = 0;
    start_t = clock();
    for (; i < 100000; ++i)
    {
        //do someting;
    }
    finish_t = clock();
    total_t = (double)(finish_t - start_t) / CLOCKS_PER_SEC;//将时间转换为秒

    printf("CPU 占用的总时间：%f\n", total_t);
    return 0;
}

2：time函数
函数原型 : time_t time(time_t * timer)
参数说明 : timer = NULL时得到当前日历时间（从1970 - 01 - 01 00 : 00 : 00到现在的秒数），timer = 时间数值时，用于设置日历时间，time_t是一个unsigned long类型。如果 timer不为空，则返回值也存储在变量 timer中。
函数功能 : 得到当前日历时间或者设置日历时间
函数返回 : 当前日历时间


#include <stdio.h>
#include <time.h>

int main()
{
	time_t seconds;

	seconds = time(NULL);
	printf("自 1970-01-01 起的小时数 = %ld\n", seconds / 3600);

	return(0);
}

3：asctime函数
函数原型 : char* asctime(struct tm* ptr)
函数功能 : 将结构struct tm * ptr所表示的时间以字符串表示
函数返回 : 返回的时间字符串格式为：星期, 月, 日, 小时 : 分 : 秒, 年
参数说明 : 结构指针ptr应通过函数localtime()或gmtime()得到

#include <stdio.h>
#include <time.h>

int main()
{
	struct tm t;//更多情况下是通过localtime函数及gmtime函数获得tm结构

	t.tm_sec = 10;
	t.tm_min = 10;
	t.tm_hour = 6;
	t.tm_mday = 25;
	t.tm_mon = 2;
	t.tm_year = 89;
	t.tm_wday = 6;

	printf("%s\n", asctime(&t));

	return(0);
}


4：localtime函数
函数原型 : struct tm* localtime(const time_t * timer)
函数功能 : 使用 timer 的值来填充 tm 结构。timer 的值被分解为 tm 结构，并用本地时区表示。
函数返回 : 以tm结构表达的时间

#include <stdio.h>
#include <time.h>

int main()
{
	time_t timer;
	struct tm* Now;

	time(&timer);
	Now = localtime(&timer);
	printf("当前的本地时间和日期：%s", asctime(Now));

	return(0);
}

5：ctime函数
函数原型 : char* ctime(const time_t * timer)
函数功能 : 将日历时间参数timer转换为一个表示本地当前时间的字符串
函数返回 : 返回字符串格式：星期, 月, 日, 小时 : 分 : 秒, 年
参数说明 : timer参数应由函数time获得，其等价于 astime(localtime(timer))

#include <stdio.h>
#include <time.h>

int main()
{
	time_t curtime;
	time(&curtime);
	printf("当前时间 = %s", ctime(&curtime));

	return(0);
}

6：difftime函数
函数原型 : double difftime(time_t time2, time_t time1)
函数功能 : 得到两次机器时间差，单位为秒
函数返回 : 时间差，单位为秒
参数说明 : time1, time2分别表示两个不同的机器时间，该参数应使用time函数获得
1
2
3
4
#include <time.h>  
#include <stdio.h>  
int main()
{
    time_t first, second;
    time(&first);
    sleep(2000);
    time(&second);
    printf("The difference is: %f seconds", difftime(second, first));

    return 0;
}

7：gmtime函数
函数原型 : struct tm* gmtime(time_t * timer)
函数功能 : 得到以结构tm表示的时间信息，并用格林威治标准时间表示
函数返回 : 以结构tm表示的时间信息指针
参数说明 : timer用函数time()得到的时间信息

#include <stdio.h>
#include <time.h>

#define BST (+1)
#define CCT (+8)

int main()
{

	time_t rawtime;
	struct tm* info;

	time(&rawtime);
	/* 获取 GMT 时间 */
	info = gmtime(&rawtime);

	printf("当前的世界时钟：\n");
	printf("伦敦：%2d:%02d\n", (info->tm_hour + BST) % 24, info->tm_min);
	printf("中国：%2d:%02d\n", (info->tm_hour + CCT) % 24, info->tm_min);

	return(0);
}


8：mktime函数
函数原型：time_t mktime(struct tm* timeptr)
函数功能：把 timeptr 所指向的结构转换为一个依据本地时区的 time_t 值
函数返回：该函数返回一个 time_t 值，该值对应于以参数传递的日历时间。如果发生错误，则返回 - 1 值。

#include <stdio.h>
#include <time.h>

int main()
{
    int ret;
    struct tm info;
    char buffer[80];

    info.tm_year = 2001 - 1900;
    info.tm_mon = 7 - 1;
    info.tm_mday = 4;
    info.tm_hour = 0;
    info.tm_min = 0;
    info.tm_sec = 1;
    info.tm_isdst = -1;

    ret = mktime(&info);
    if (ret == -1)
    {
        printf("错误：不能使用 mktime 转换时间。\n");
    }
    else
    {
        strftime(buffer, sizeof(buffer), "%c", &info);
        print(buffer);
    }

    return(0);
}

9：strftime函数
函数原型 : size_t strftime(char* strDest, size_t  maxsize, const char* format, const struct tm* timeptr);
函数功能: 根据format指向字符串中格式命令把timeptr中保存的时间信息放在strDest指向的字符串中，最多向 strDest中存放maxsize个字符。
参数说明 : 转化结果存在s中，最多maxsize个字符写到s中
函数返回 : 该函数返回向strDest指向的字符串中放置的字符数（不包括'\0'），如果字符数多于maxsize，函数返回0.

format如下：它们是区分大小写的。
    %a 星期几的简写
    %A 星期几的全称
    %b 月分的简写
    %B 月份的全称
    %c 标准的日期的时间串
    %C 年份的后两位数字
    %d 十进制表示的每月的第几天
    %D 月/天/年
    %e 在两字符域中，十进制表示的每月的第几天
    %F 年-月-日
    %g 年份的后两位数字，使用基于周的年
    %G 年分，使用基于周的年
    %h 简写的月份名
    %H 24小时制的小时
    %I 12小时制的小时
    %j 十进制表示的每年的第几天
    %m 十进制表示的月份
    %M 十时制表示的分钟数
    %n 新行符
    %p 本地的AM或PM的等价显示
    %r 12小时的时间
    %R 显示小时和分钟：hh:mm
    %S 十进制的秒数
    %t 水平制表符
    %T 显示时分秒：hh:mm:ss
    %u 每周的第几天，星期一为第一天 （值从0到6，星期一为0）
    %U 第年的第几周，把星期日做为第一天（值从0到53）
    %V 每年的第几周，使用基于周的年
    %w 十进制表示的星期几（值从0到6，星期天为0）
    %W 每年的第几周，把星期一做为第一天（值从0到53）
    %x 标准的日期串
    %X 标准的时间串
    %y 不带世纪的十进制年份（值从0到99）
    %Y 带世纪部分的十进制年份
    %z，%Z 时区名称，如果不能得到时区名称则返回空字符。
    %% 百分号


#include <stdio.h>
#include <time.h>

int main()
{
    time_t rawtime;
    struct tm* info;
    char buffer[80];

    time(&rawtime);

    info = localtime(&rawtime);

    strftime(buffer, 80, "%Y%m%e_%H%M%S", info);//以年月日_时分秒的形式表示当前时间
    printf("%s\n", buffer);

    return(0);
}
