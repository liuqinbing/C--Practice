/*存储映射I/O：mmap、memcpy、msync、mprotect、munmap函数*/
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
    int fdin, fdout;
    void *src, *dst;
    struct stat statbuf;

    if((fdin = open("p16_1.in", O_RDONLY)) == -1)
    {
        perror("open p16_1.in failed\n");
        exit(1);
    }

    if((fdout = open("p16_1.out", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
    {
        perror("open p16_1.out failed");
        exit(1);
    }

    fstat(fdin, &statbuf);

    //目前文件为空，需要添加内容将其加长
    lseek(fdout, statbuf.st_size-1, SEEK_SET);
    write(fdout, "", 1);
    //ftruncate(fdout, statbuf.st_size);//扩充文件的长度

    //将文件映射到存储区域
    //第一个参数是映射存储区的起始地址（通常设为0，由系统自己选择）
    //第二个参数是映射的字节数
    //第三个参数是映射存储区的权限
    //第四个参数是映射存储区的属性
    //第五个参数是被映射的文件描述符
    //第六个参数是要映射的起始字节在文件中的偏移量（必须是分页大小的整数倍）
    src = mmap(0, statbuf.st_size, PROT_READ, MAP_SHARED, fdin, 0);

    dst = mmap(0, statbuf.st_size, PROT_READ, MAP_SHARED, fdout, 0);

    //修改映射存储区的权限
    mprotect(dst, statbuf.st_size, PROT_WRITE);

    //将存储区的内容复制到另一个存储区
    memcpy(dst, src, statbuf.st_size);

    //立即将存储区的内容同步到文件中
    msync(dst, statbuf.st_size, MS_SYNC);

    //解除文件和映射存储区的映射关系（关闭文件描述符并不会解除）
    munmap(dst, statbuf.st_size);

    munmap(src, statbuf.st_size);

    return 0;
}