//find the size of pipe
#include<stdio.h>
#include<unistd.h>

int main()
{
    int res,arr[2],counter=0;
    char buf='A';
    res = pipe(arr);
    if(res < 0)
    {
        perror("pipe failed");
        _exit(0);
    }
    while(1)
    {
        write(arr[1],&buf,sizeof(buf));
        counter++;
        printf("count : %d\n",counter);
    }
    close(arr[1]);

    return 0;
}