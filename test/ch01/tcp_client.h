/*
 * @Author: ImGili
 * @Description: 
 */

#include"core.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<unistd.h>

#include<sys/socket.h>
#include<arpa/inet.h>
namespace glx0106
{
    int main(int argc, char* argv[])
    {
        int sock;
        sockaddr_in serv_addr;

        char message[30];
        int str_len;
        int idx = 0, read_len = 0;
        
        if (argc != 3)
        {
            printf("Useage: %s <IP> <port>", argv[0]);
            exit(1);
        }
        
        sock = socket(PF_INET, SOCK_STREAM, 0);
        if (sock==-1)
        {
            error_handling("socket() ERROR!");
        }

        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = PF_INET;
        serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
        serv_addr.sin_port = htons(atoi(argv[2]));

        if (connect(sock, (sockaddr*)&serv_addr, sizeof(serv_addr))==-1)
        {
            error_handling("connect() ERROR");
        }

        while (read_len = read(sock, &message[idx++], 1))
        {
            if (read_len == -1)
            {
                error_handling("read() ERROR");
            }
            str_len += read_len;            
        }
        printf("server message: %s\n", message);
        printf("read count: %d\n", str_len);
        close(sock);
        
        return 0;
    }
}