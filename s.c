#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>


short SocketCreate(void)
{
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}


int BindCreatedSocket(int hSocket)
{
    int iRetval=-1;
    int ClientPort = 8080;
    struct sockaddr_in  remote= {0};
    /* Internet address family */
    remote.sin_family = AF_INET;
    /* Any incoming interface */
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(ClientPort); /* Local port */
    iRetval = bind(hSocket,(struct sockaddr *)&remote,sizeof(remote));
    return iRetval;
}


int main(int argc, char *argv[])
{
    int socket_desc, sock, clientLen, read_size;
    struct sockaddr_in server, client;
    
    char client_message[1000]= {0};
    const char *auth_token  = "Ae*%$3s8ac";

    socket_desc = SocketCreate();
    
    if (socket_desc == -1)
    {
        printf("Could not create socket");
        return 1;
    }
    
    printf("Socket created\n");

    //Bind
    if( BindCreatedSocket(socket_desc) < 0)
    {
        //print the error message
        perror("bind failed.");
        return 1;
    }
    
    printf("bind done\n");
    
    //Listen
    listen(socket_desc, 3);

    //Accept and incoming connection
    while(1)
    {
        printf("Waiting for incoming connections...\n");
        
        clientLen = sizeof(struct sockaddr_in);
        
        //accept connection from an incoming client
        sock = accept(socket_desc,(struct sockaddr *)&client,(socklen_t*)&clientLen);
        
        if (sock < 0)
        {
            perror("accept failed");
            return 1;
        }
        
        printf("Connection accepted\n");


        if( recv(sock, client_message, 1000, 0) < 0)
        {
            printf("recv failed");
            break;
        }
        
        printf("Client reply : %s\n",client_message);

        
        char message[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html;\r\nContent-Length: 249\r\nConnection: close\r\n\r\n<html><head><title>Hello</title></head><body><form method=\"post\">str_param:<input maxlength=\"25\" size=\"40\" name=\"str_param\"/><br>token:<input maxlength=\"25\" size=\"40\" name=\"token\"/><br><input name=\"\" type=\"submit\" value=\"send\"/></form></body></html>";
        int sent;
        for (sent = 0; sent < sizeof(message); sent += send(sock, message+sent, sizeof(message)-sent, 0));


        // тут вырезаем токен и сравниваем
        // если токен ок то отправляем страницу со значениями параметров, 
        // если нет, то заглушку, что пользователь не авторизован


        close(sock);
        sleep(1);
    }

    return 0;

}