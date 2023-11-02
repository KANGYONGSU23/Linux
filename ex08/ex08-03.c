#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
	pid_t pid1, pid2;
	int status;

	pid1 = pid2 = -1;

	int x,y;
	scanf("%d %d",&x,&y);

	pid1 = fork();
	if(pid1 > 0)
	{
		pid2 = fork();
	}

	if(pid1>0 && pid2>0)
	{
		int answer;
		
		int pow = 1;
		for(int i =0;i<y;i++)
		{
			pow *= x;
		}
		
		waitpid(pid2, &status, 0);
		printf("%d\n",answer);
		answer = status>>8;
		printf("%d\n",answer);
		waitpid(pid1, &status, 0);
		answer = answer - status>>8;
		printf("pow : %d\n",pow);
		answer = answer - pow;
		
		
		printf("answer : %d\n",answer);
	}
	else if(pid1 == 0 && pid2 == -1)
	{
		sleep(1);
		int result;
		for(int i = x; i<=y;i++)
		{
			result += i;
		}
		printf("pid1 : %d\n",result);
		exit(result);
	}
	else if(pid1 > 0 && pid2 == 0)
	{
		sleep(2);
		int result;
		for(int i = x; i<=y; i++)
		{
			result *= i;
		}
		printf("pid2 : %d\n",result);
		exit(result);
	}
}
