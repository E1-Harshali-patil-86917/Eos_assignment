#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/msg.h>
#define MQ_KEY 0x1234

typedef struct msg{
    long id;
    int data1;
    int data2;
    int res;

}msg;

int main()
{
    int res,s,mqid;
    mqid = msgget(MQ_KEY,IPC_CREAT|0644);
    if(mqid<0)
    {
        perror("msgget failed");
        _exit(0);
    }

    res = fork();
    if(res == -1)
    {
      perror("fork failed!");
      _exit(0);

    }
    if(res == 0)
    {
        msg m1;
        m1.id = 100;
        printf("enter two integer:");
        scanf("%d%d,&m1.data1,&m1.data2");
        res = msgsnd(mqid,&m1,sizeof(msg)-sizeof(long),0);
        if(res<0)
        {
            perror("child msgsnd failed");
            _exit(0);
        }
        else
        {
            printf("first integer send : %d\n",m1.data1);
            printf("second integer send : %d\n",m1.data2);
        }

        printf("waiting for parent to send a result\n");
        msg m2;
        res = msgrcv(mqid,&m2,sizeof(msg)-sizeof(long),101,0);
        if(res<0)
        {
            perror("child msgrcv failed!!!");
            _exit(0);
        }
        else
        {
            printf("result received : %d\n",m2.res);
        }

    }
    else
    {
        
        msg m3;
        res = msgrcv(mqid,&m3,sizeof(msg)-sizeof(long),100,0);
        if(res<0)
        {
            perror("parent msgrcv failed!!!");
            _exit(0);
        }
        else
        {
            printf("received data : %d and %d\n",m3.data1,m3.data2);
        }
        msg m4;
        m4.id =101;

        m4.res = m3.data1 + m3.data2;
        
        res = msgsnd(mqid,&m4,sizeof(msg)-sizeof(long),0);
        if(res<0)
        {
            perror("parent msgsnd failed!!!");
            _exit(0);
        }
        else
        {
            waitpid(res,&s,0);
            msgctl(mqid,IPC_RMID,NULL);
        }
    }
    

    return 0;
}
        
    
