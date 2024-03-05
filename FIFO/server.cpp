#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
    int pd , n;
    char msg[] = "Hello, FIFO";

    printf("Server =====\n");
    mkfifo("./pipeFile", 0660);

    if((pd = open("./pipeFile", O_CREAT | O_WRONLY)) ==  -1)
    {
        perror("open"); exit(1);
    }

    printf("To Client : %s\n", msg);
    n = write(pd, msg, strlen(msg) + 1);

    if(n == -1)
    {
        perror("write"); exit(1);
    }
    close(pd);
    return 0;
}