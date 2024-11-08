#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{

	int ret,s;
	for(int i=1; i<=5; i++){
		ret = fork();
		if(ret == 0){
			for(int j=1; j<=5; j++){
				printf("Pid: %d Child number: %d Count: %d\n", getpid(), i, j);
				sleep(5);
			}
			_exit(i);
		}
	}
	for(int i=1; i<=5; i++){
		wait(&s);
		printf("Exit status: %d\n", WEXITSTATUS(s));
	}
	return 0;
}