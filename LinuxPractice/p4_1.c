/*时间和日期：time、difftime、localtime、gmtime、mktime、asctime、ctime函数*/
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    struct tm *tm_ptr;//时间结构体
    time_t raw_time1;//底层时间值（从纪元开始到现在的秒数）
    time_t raw_time2;
    double diff;//时间差

    time(&raw_time1);//获取底层时间
    printf("底层未处理的时间：%ld\n", raw_time1);

    sleep(2);//休眠两秒

    time(&raw_time2);
    diff = difftime(raw_time2, raw_time1);//计算两个时间的差
    printf("间隔时间：%g\n", diff);

    //gmtime和localtime函数作用相同
    //gmtime是按GMT返回时间
    //localtime是按当地地区和是否采用夏令营做调整
    tm_ptr = localtime(&raw_time2);//将未处理的底层时间处理成可读的时间和日期，保存在结构体中
    //raw_time2 = mktime(tm_ptr);//将tm结构体转成底层时间格式

    printf("日期：%4d/%02d/%02d\n", tm_ptr->tm_year+1900, tm_ptr->tm_mon+1, tm_ptr->tm_mday);//年份是从1900年到现在的差；月份tm_mon是0~11，所以加一
    printf("时间：%02d:%02d:%02d\n", tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);

    printf("date命令的时间格式：%s\n", asctime(tm_ptr));//将tm结构转成date命令的时间格式
    printf("date命令的时间格式：%s\n", ctime(&raw_time2));//将底层时间转成date命令的时间格式，按当地地区和是否采用夏令营做调整

    return 0;
}