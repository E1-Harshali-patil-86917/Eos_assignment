#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(){
    int sig,pid;

    //input from the user
    printf("Enter signal number:");
    scanf("%d", &sig);

    //input process
    printf("Enter process ID:");
    scanf("%d",&pid);

    if(kill(pid, sig)==0){
        printf("signal %d successfully sent to process %d\n",sig,pid);

    }
    else{
        perror("failed to sent signal");

    }
    return 0;
}