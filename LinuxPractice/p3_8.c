/*目录操作*/
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir(char *dir, int depth)
{
    DIR *dp;
    struct dirent *entry;  //存储目录项的节点号d_ino和名称d_name等信息
    struct stat statbuf;     //存储目录项的属性

    if((dp = opendir(dir)) == NULL)//打开目录，并获取目录流
    {
        fprintf(stderr, "无法打开目录: %s/\n", dir);
        return;
    }

    chdir(dir);  //操作目录前，需要先切换到目录的位置

    //递归遍历，查询全部的目录项
    while((entry = readdir(dp)) != NULL)//读取该目录流中的一个目录项
    {
        lstat(entry->d_name, &statbuf);//获取该目录项的属性

        //判断该目录项是否为目录，如果是，则对它进行递归遍历
        if(S_ISDIR(statbuf.st_mode))
        {
            //跳过.和..目录项jieshu
            if(strcmp(".",entry->d_name)==0 || strcmp("..", entry->d_name)==0)
                continue;

            fprintf(stdout, "%*s%s/\n", depth, " ", entry->d_name);//输出目录名
            
            printdir(entry->d_name, depth+4);//递归遍历该目录
        }
        else{
            fprintf(stdout, "%*s%s\n", depth, " ", entry->d_name);//输出文件名 
        }
    }

    chdir("..");//遍历完该目录的目录项，返回上级目录

    closedir(dp);//关闭该目录流，防止打开的目录流超过限制
}

int main(int argc, char* argv[])
{
    char *topdir = ".";//默认为当前目录

    //当为多条命令时
    if(argc >= 2)
    {
        topdir = argv[1]; //获取字符串数组的第二个值，即目录地址
    }

    fprintf(stdout, "%s/目录结构如下：\n", topdir);

    printdir(topdir, 2);

    fprintf(stdout, "结束\n");

    return 0;
}