/*底层文件操作：关于lseek系统调用，对读写指针进行设置*/
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    char buffer[4];
    int in = open("LinuxPractice/p3_1.in", O_RDONLY|O_WRONLY);

    lseek(in, 1, SEEK_SET);//设置读写指针位置

    read(in, buffer, 4);//读指针位置变化并不会影响写指针位置
    write(in, "buff", 4);

    exit(0);
}