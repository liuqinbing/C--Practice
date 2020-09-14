/*内存分配和释放：malloc函数（返回void *类型的内存地址）、realloc函数、free函数*/
#include <stdlib.h>
#include <stdio.h>

#define A_MEGABYTE (1024 * 1024)

int main()
{
    char *some_memory;
    int megabyte = A_MEGABYTE;
    
    some_memory = (char *)malloc(megabyte);//获取可用内存，返回void *指针类型，可以转成任何类型的指针

    if(some_memory != NULL)
    {
        sprintf(some_memory, "hello world!");//往内存中写入数据
        printf("%s\n", some_memory);

        some_memory = realloc(some_memory, 1024*1024);//根据size值，增加或减小内存块长度

        printf("%s\n", some_memory);

        free(some_memory);//释放内存
    }

    return 0;
}