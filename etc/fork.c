#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t pid;
	int i = 1;
	int input;
	scanf("%d", &input);

	pid = fork();



	if(pid > 0) //parent 
	{	
		int sum = 0;
		for(int i = 1;i<=input;i++)
		{
			sum+=i;
		}
		printf("%d\n",sum);	
	}
	
	else if (pid == 0) //children
	{
		int sum = 1;
		for(int i = 1; i<=input;i++)
		{
			sum*=i;
		}
		printf("%d\n",sum);
	}
	else
	{
		printf("fork failed");
	}
}
