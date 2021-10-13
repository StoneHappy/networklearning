#include<stdlib.h>
#include"ch01/hello_client.h"
#include"ch01/hello_server.h"
#include"ch01/low_open.h"
#include"ch01/low_read.h"
#include"ch01/fd_seri.h"
#include"ch01/tcp_client.h"
#include"ch01/ex_server.h"
#include<iostream>
int main()
{
    int flag = 1;
    std::cout << "101、第一章 hello_server" << std::endl;
    std::cout << "102、第一章 hello_client" << std::endl;
    std::cout << "103、第一章 low_open" << std::endl;
    std::cout << "104、第一章 low_read" << std::endl;
    std::cout << "105、第一章 fd_seri" << std::endl;
    std::cout << "106、第一章 tcp_client" << std::endl;
    std::cout << "107、第一章 ex_server" << std::endl;
    std::cin >> flag;
    char** tmp;
    switch (flag)
    {
    case 101:
        *(tmp+1) = "5400";
        glx0101::main(2, tmp);
        break;
    case 102:
        *(tmp+1) = "127.0.0.1";
        *(tmp+2) = "5400";
        glx0102::main(3, tmp);
        break;
    case 103:
        glx0103::main();
        break;
    case 104:
        glx0104::main();
        break;
    case 105:
        glx0105::main();
        break;
    case 106:
        *(tmp+1) = "127.0.0.1";
        *(tmp+2) = "5400";
        glx0106::main(3, tmp);
        break;
    case 107:
        *(tmp+1) = "5400";
        glx0107::main(2, tmp);
        break;
    default:
        break;
    }
    return 0;
}