#pragma once
#include"core.h"
#include<fcntl.h>
#include<unistd.h>
namespace glx0103
{
    int main()
    {
        int fd;
        char buf[] = "Let's go!\n";
        
        fd = open("resources/data/data.txt", O_CREAT|O_WRONLY|O_TRUNC);
        if (fd == -1)
        {
            error_handling("open() error!");
        }

        printf("file descriptor: %d\n", fd);

        if (write(fd, buf, sizeof(buf)-1) == -1)
        {
            error_handling("write() error!");
        }
        close(fd);
        return 0;
    }
}