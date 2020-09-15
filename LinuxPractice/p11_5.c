/*输入输出重定向：freopen函数*/
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    int c;

    //将文件重定向到标准输入
    if(!freopen("./p11_5.in", "r", stdin))
    {
        fprintf(stderr, "could not redirect stdin from file ./p11_5.in\n");
        return 0;
    }

    //将标准输出重定向到文件
    if(!freopen("./p11_5.out", "w", stdout))
    {
        fprintf(stderr, "could not redirect stdout to file ./p11_5.out\n");
        return 0;
    }

    while((c = getchar()) != EOF)//从标准输入获取一个字符，即从文件p11_5.in获取字符
    {
        putchar(toupper(c));//将字符转成大写，然后输出到标准输出，即向文件p11_5.out写入字符
    }

    return 0;
}