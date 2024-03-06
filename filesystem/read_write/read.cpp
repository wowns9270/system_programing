#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
    int rfd, wfd, n;

    char buf[10];

    rfd = open("hello.txt", O_RDONLY);
    if(rfd == -1)
    {
        perror("Open hello.txt");
        exit(1);
    }

    wfd = open("hello.bak" , O_CREAT| O_WRONLY | O_TRUNC, 0644);
    if(wfd == -1)
    {
        perror("Open hello.bak");
        exit(1);
    }

    while((n = read(rfd, buf, 6)) > 0)
    {
       if( n != write(wfd, buf, n))
       {
        perror("write error");
       } 
    }

    if(n == -1) perror("read error");

    close(rfd);
    close(wfd);

}