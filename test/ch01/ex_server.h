/*
 * @Author: ImGili
 * @Description: 
 */
#include<string.h>
#include<stdio.h>
#include"core.h"
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
namespace glx0107
{
    int main(int argc, char* argv[])
    {
        int serv_sock;
        int clnt_sock;
        
        sockaddr_in serv_addr;
        sockaddr_in clnt_addr;

        socklen_t clnt_addr_size;

        char message[] = "hello world!\0";
        if (argc != 2)
        {
            printf("Usage: %s <port>", argv[0]);
            exit(-1);
        }

        serv_sock = socket(PF_INET, SOCK_STREAM, 0);
        if (serv_sock == -1)
        {
            error_handling("socket() ERROR!");
        }

        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        serv_addr.sin_port = htons(atoi(argv[1]));
        // memset(&clnt_addr, 0, sizeof(clnt_addr));

        if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        {
            error_handling("bind() error");
        }

        if (listen(serv_sock, 5) == -1)
        {
            error_handling("listen() error");
        }
        // 接听电话
        clnt_addr_size = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock, (sockaddr*)&clnt_addr, &clnt_addr_size);

        if(clnt_sock == -1)
        {
            error_handling("accept() ERROR!");
        }

        write(clnt_sock, message, sizeof(message)/2);
        write(clnt_sock, (message + sizeof(message)/2), sizeof(message)/2);

        close(serv_sock);
        close(clnt_sock);
        return 0;
    }
}