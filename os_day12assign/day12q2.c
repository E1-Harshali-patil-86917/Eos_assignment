
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int ret1,ret2,arr1[2],arr2[2],s,result,buff;
    int num1,num2,read1,read2;
    ret1 = pipe(arr1);
    if(ret1<0)
    {
        perror("pipe failed");
        _exit(0);
    }
    ret2= pipe(arr2);
        if(ret2<0)
        {
            perror("pipe failed");
            _exit(0);
        }
    ret1 =fork();
    if(ret1 == 0)
    {
        printf("child : enter two integers :");
        scanf("%d%d",&num1,&num2);
        close(arr1[0]);
        write(arr1[1],&num1,sizeof(num1));
       
        write(arr1[1],&num2,sizeof(num2));
        printf("child written to pipe :%d and %d\n",num1,num2);
        close(arr1[1]);
        printf("waiting for parent to send result\n");
        close(arr2[1]);
        read(arr2[0],&buff,sizeof(buff));
        printf("result received from parent : %d\n",buff);
        close(arr2[0]);
    } 
    else
    {
        
        close(arr1[1]);
        printf("waiting for child to send message\n");
        read(arr1[0],&read1,sizeof(read1));
        
        read(arr1[0],&read2,sizeof(read2));
        result = read1+read2;
        printf("parent : read from pipe : %d and %d\n",read1,read2);
        close(arr1[0]);
        close(arr2[0]);
        write(arr2[1],&result,sizeof(result));
        printf("parent written to pipe :%d\n",result);
        
        waitpid(ret1,&s,0);
        close(arr2[1]);
    }

    return 0;
}