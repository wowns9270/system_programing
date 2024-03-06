#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>


int main()
{
    int fd, n;
    off_t start, cur;
    char buf[256];

    fd = open("linux.txt", O_RDONLY);
    if(fd == -1)
    {
        perror("Open linux.txt");
        exit(1);
    }

    start = lseek(fd, 0, SEEK_CUR);
    n = read(fd, buf, 255);
    buf[n] = '\0';
    printf("Offset start=%d, read str=%s, n=%d\n", (int)start, buf, n);
    cur = lseek(fd, 0 , SEEK_CUR);

    start = lseek(fd, 6, SEEK_SET);
    n = read(fd, buf, 255);
    printf("Offset start=%d, read str=%s, n=%d\n", (int)start, buf, n);

    close(fd);
    return 0;
}