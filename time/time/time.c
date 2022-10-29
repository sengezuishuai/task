#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>
#include<string.h>

����о����õ�ʱ���Ｐת���ĺ��������Ƕ�������time.h�⺯���У��ڴ���һ���ܽᣬ�Է�������鿴ʹ�á�

����ʱ����
1��Coordinated Universal Time(UTC)��
Э������ʱ���ֳ������׼ʱ�䣬Ҳ���������α�׼ʱ��(Greenwich Mean Time, GMT)���й��ڵص�ʱ����UTC��ʱ��Ϊ + 8��Ҳ��UTC + 8������ΪUTC - 5��

2��Calendar Time��
����ʱ�䣬���á���һ����׼ʱ��㵽��ʱ��ʱ�侭��������������ʾ��ʱ�䡣��׼ʱ���Բ�ͬ���������ܻ᲻ͬ������һ������ϵͳ��˵����׼ʱ���ǲ���ġ�һ���Ǳ�ʾ����UTCʱ�� 1970 - 01 - 01 00:00 : 00��������
3��epoch��
ʱ��㡣�ڱ�׼c / c++����һ���������ô�ʱ��ʱ��ͱ�׼ʱ�������������������ʱ�䣩����ʾ��
4��clock tick��
ʱ�Ӽ�ʱ��Ԫ����������ʱ�ӵδ��������һ��ʱ�Ӽ�ʱ��Ԫ��ʱ�䳤������cpu���Ƶģ�һ��clock tick����cpu��һ��ʱ�����ڣ�����c / c++��һ��������ʱ��λ��

time.h�Ķ���
time.h ͷ�ļ��������ĸ��������͡�������͸��ֲ������ں�ʱ��ĺ�����

4������
size_t	���޷����������ͣ����� sizeof �ؼ��ֵĽ����
clock_t	����һ���ʺϴ洢������ʱ������ͣ�����Ϊunsigned long
time_t	����һ���ʺϴ洢����ʱ�����͡�
struct tm	����һ����������ʱ������ڵĽṹ��
	
tm �ṹ�Ķ������£�
struct tm
{
	int tm_sec;         /* �룬��Χ�� 0 �� 59      */
	int tm_min;         /* �֣���Χ�� 0 �� 59      */
	int tm_hour;        /* Сʱ����Χ�� 0 �� 23     */
	int tm_mday;        /* һ���еĵڼ��죬��Χ�� 1 �� 31    */
	int tm_mon;         /* �£���Χ�� 0 �� 11(ע��)  */
	int tm_year;        /* �� 1900 ���������      */
	int tm_wday;        /* һ���еĵڼ��죬��Χ�� 0 �� 6 */
	int tm_yday;        /* һ���еĵڼ��죬��Χ�� 0 �� 365   */
	int tm_isdst;       /* ����ʱ               */
};

������
NULL	�������һ����ָ�볣����ֵ��
CLOCKS_PER_SEC	������ʾÿ��Ĵ�����ʱ�Ӹ��������ڽ�clock()�����Ľ��ת��Ϊ����Ϊ��λ������
������ľ���ֵ�������ϵͳ��صģ�ͨ��Ϊ1000��

�⺯��
1��clock����
����ԭ�ͣ�   clock_t clock(void)
�������أ�����clock����ִ����һ��Ϊ����Ŀ�ͷ����������ʱ����ʹ�õ�ʱ�䡣
�������ܣ�����������������ĳһ�ε�ִ��ʱ�䡣

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
    total_t = (double)(finish_t - start_t) / CLOCKS_PER_SEC;//��ʱ��ת��Ϊ��

    printf("CPU ռ�õ���ʱ�䣺%f\n", total_t);
    return 0;
}

2��time����
����ԭ�� : time_t time(time_t * timer)
����˵�� : timer = NULLʱ�õ���ǰ����ʱ�䣨��1970 - 01 - 01 00 : 00 : 00�����ڵ���������timer = ʱ����ֵʱ��������������ʱ�䣬time_t��һ��unsigned long���͡���� timer��Ϊ�գ��򷵻�ֵҲ�洢�ڱ��� timer�С�
�������� : �õ���ǰ����ʱ�������������ʱ��
�������� : ��ǰ����ʱ��


#include <stdio.h>
#include <time.h>

int main()
{
	time_t seconds;

	seconds = time(NULL);
	printf("�� 1970-01-01 ���Сʱ�� = %ld\n", seconds / 3600);

	return(0);
}

3��asctime����
����ԭ�� : char* asctime(struct tm* ptr)
�������� : ���ṹstruct tm * ptr����ʾ��ʱ�����ַ�����ʾ
�������� : ���ص�ʱ���ַ�����ʽΪ������, ��, ��, Сʱ : �� : ��, ��
����˵�� : �ṹָ��ptrӦͨ������localtime()��gmtime()�õ�

#include <stdio.h>
#include <time.h>

int main()
{
	struct tm t;//�����������ͨ��localtime������gmtime�������tm�ṹ

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


4��localtime����
����ԭ�� : struct tm* localtime(const time_t * timer)
�������� : ʹ�� timer ��ֵ����� tm �ṹ��timer ��ֵ���ֽ�Ϊ tm �ṹ�����ñ���ʱ����ʾ��
�������� : ��tm�ṹ����ʱ��

#include <stdio.h>
#include <time.h>

int main()
{
	time_t timer;
	struct tm* Now;

	time(&timer);
	Now = localtime(&timer);
	printf("��ǰ�ı���ʱ������ڣ�%s", asctime(Now));

	return(0);
}

5��ctime����
����ԭ�� : char* ctime(const time_t * timer)
�������� : ������ʱ�����timerת��Ϊһ����ʾ���ص�ǰʱ����ַ���
�������� : �����ַ�����ʽ������, ��, ��, Сʱ : �� : ��, ��
����˵�� : timer����Ӧ�ɺ���time��ã���ȼ��� astime(localtime(timer))

#include <stdio.h>
#include <time.h>

int main()
{
	time_t curtime;
	time(&curtime);
	printf("��ǰʱ�� = %s", ctime(&curtime));

	return(0);
}

6��difftime����
����ԭ�� : double difftime(time_t time2, time_t time1)
�������� : �õ����λ���ʱ����λΪ��
�������� : ʱ����λΪ��
����˵�� : time1, time2�ֱ��ʾ������ͬ�Ļ���ʱ�䣬�ò���Ӧʹ��time�������
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

7��gmtime����
����ԭ�� : struct tm* gmtime(time_t * timer)
�������� : �õ��Խṹtm��ʾ��ʱ����Ϣ�����ø������α�׼ʱ���ʾ
�������� : �Խṹtm��ʾ��ʱ����Ϣָ��
����˵�� : timer�ú���time()�õ���ʱ����Ϣ

#include <stdio.h>
#include <time.h>

#define BST (+1)
#define CCT (+8)

int main()
{

	time_t rawtime;
	struct tm* info;

	time(&rawtime);
	/* ��ȡ GMT ʱ�� */
	info = gmtime(&rawtime);

	printf("��ǰ������ʱ�ӣ�\n");
	printf("�׶أ�%2d:%02d\n", (info->tm_hour + BST) % 24, info->tm_min);
	printf("�й���%2d:%02d\n", (info->tm_hour + CCT) % 24, info->tm_min);

	return(0);
}


8��mktime����
����ԭ�ͣ�time_t mktime(struct tm* timeptr)
�������ܣ��� timeptr ��ָ��Ľṹת��Ϊһ�����ݱ���ʱ���� time_t ֵ
�������أ��ú�������һ�� time_t ֵ����ֵ��Ӧ���Բ������ݵ�����ʱ�䡣������������򷵻� - 1 ֵ��

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
        printf("���󣺲���ʹ�� mktime ת��ʱ�䡣\n");
    }
    else
    {
        strftime(buffer, sizeof(buffer), "%c", &info);
        print(buffer);
    }

    return(0);
}

9��strftime����
����ԭ�� : size_t strftime(char* strDest, size_t  maxsize, const char* format, const struct tm* timeptr);
��������: ����formatָ���ַ����и�ʽ�����timeptr�б����ʱ����Ϣ����strDestָ����ַ����У������ strDest�д��maxsize���ַ���
����˵�� : ת���������s�У����maxsize���ַ�д��s��
�������� : �ú���������strDestָ����ַ����з��õ��ַ�����������'\0'��������ַ�������maxsize����������0.

format���£����������ִ�Сд�ġ�
    %a ���ڼ��ļ�д
    %A ���ڼ���ȫ��
    %b �·ֵļ�д
    %B �·ݵ�ȫ��
    %c ��׼�����ڵ�ʱ�䴮
    %C ��ݵĺ���λ����
    %d ʮ���Ʊ�ʾ��ÿ�µĵڼ���
    %D ��/��/��
    %e �����ַ����У�ʮ���Ʊ�ʾ��ÿ�µĵڼ���
    %F ��-��-��
    %g ��ݵĺ���λ���֣�ʹ�û����ܵ���
    %G ��֣�ʹ�û����ܵ���
    %h ��д���·���
    %H 24Сʱ�Ƶ�Сʱ
    %I 12Сʱ�Ƶ�Сʱ
    %j ʮ���Ʊ�ʾ��ÿ��ĵڼ���
    %m ʮ���Ʊ�ʾ���·�
    %M ʮʱ�Ʊ�ʾ�ķ�����
    %n ���з�
    %p ���ص�AM��PM�ĵȼ���ʾ
    %r 12Сʱ��ʱ��
    %R ��ʾСʱ�ͷ��ӣ�hh:mm
    %S ʮ���Ƶ�����
    %t ˮƽ�Ʊ��
    %T ��ʾʱ���룺hh:mm:ss
    %u ÿ�ܵĵڼ��죬����һΪ��һ�� ��ֵ��0��6������һΪ0��
    %U ����ĵڼ��ܣ�����������Ϊ��һ�죨ֵ��0��53��
    %V ÿ��ĵڼ��ܣ�ʹ�û����ܵ���
    %w ʮ���Ʊ�ʾ�����ڼ���ֵ��0��6��������Ϊ0��
    %W ÿ��ĵڼ��ܣ�������һ��Ϊ��һ�죨ֵ��0��53��
    %x ��׼�����ڴ�
    %X ��׼��ʱ�䴮
    %y �������͵�ʮ������ݣ�ֵ��0��99��
    %Y �����Ͳ��ֵ�ʮ�������
    %z��%Z ʱ�����ƣ�������ܵõ�ʱ�������򷵻ؿ��ַ���
    %% �ٷֺ�


#include <stdio.h>
#include <time.h>

int main()
{
    time_t rawtime;
    struct tm* info;
    char buffer[80];

    time(&rawtime);

    info = localtime(&rawtime);

    strftime(buffer, 80, "%Y%m%e_%H%M%S", info);//��������_ʱ�������ʽ��ʾ��ǰʱ��
    printf("%s\n", buffer);

    return(0);
}
