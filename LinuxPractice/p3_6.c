/*格式化I/O：printf、fprintf和sprintf函数*/
#include <stdio.h>

int main()
{
    FILE *fp = fopen("LinuxPractice/p3_6.out", "w+");
    char s[] = "world!";
    char str[10];

    sprintf(str, "123456789");//将输出写到另一个字符串中，并在输出结尾添加一个空字符\0

    fprintf(fp, "hello %s %s", s, str);//将输出写到文件流

    printf("hello %s %20s\n", s, str);//将输出写到标准输出

    return 0;
}
