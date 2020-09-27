/*被p13_2_1启动的新进程*/
#include <stdio.h>

int main()
{
    char buffer[1024];

    fgets(buffer, 1024, stdin);

    fprintf(stdout, "%s\n", buffer);

    fgets(buffer, 1024, stdin);

    fprintf(stdout, "%s\n", buffer);

    return 0;
}