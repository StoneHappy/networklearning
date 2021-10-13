#pragma once
#include<fcntl.h>
#include<unistd.h>

#include"core.h"
namespace glx0104
{
#define BUFFER_SIZE 100
    int main()
    {
        int fd;
        char* buf[BUFFER_SIZE];

        fd = open("resources/data/data.txt", O_RDONLY);
        if (fd == -1)
        {
            error_handling("open() error!");
        }

        if(read(fd, buf, sizeof(buf)-1) == -1) 
        {
            error_handling("read() error");
        }
        printf("file data: %s", buf);
        
        close(fd);
        return 0;
    }
}