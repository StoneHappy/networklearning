#include<stdlib.h>
#include"ch01/hello_client.h"
#include"ch01/hello_server.h"
#include<iostream>
int main()
{
    int flag = 1;
    std::cout << "101、第一章 hello_server" << std::endl;
    std::cout << "102、第一章 hello_client" << std::endl;
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
    default:
        break;
    }
    return 0;
}