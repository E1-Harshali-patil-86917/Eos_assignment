#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

#define SOCK_FILE   "/tmp/mysock"

int main() {
    int ret, cli_fd,num1,num2,result;
    struct sockaddr_un serv_addr;
    
    //create client socket
    cli_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    // connect to server socket
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, SOCK_FILE);
    ret = connect(cli_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
   
        // send data to server
        printf("client:enter 2 numbers: ");
        scanf("%d%d",&num1,&num2);
        write(cli_fd, &num1, sizeof(num1));
        write(cli_fd, &num2, sizeof(num2));
        // read data from server
        read(cli_fd, &result, sizeof(result));
        printf("data received from server: %d\n", result);
    
    //close client socket
    close(cli_fd);
    return 0;
}