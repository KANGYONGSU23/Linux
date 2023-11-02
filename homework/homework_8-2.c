#include <stdio.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	pid_t pid;
	int status;

	int x,y;
	int powNum = 1;

	scanf("%d %d",&x,&y);
	
	pid = fork();

	if(pid > 0)
	{	
		for(int i=0;i<y;i++){
			powNum *= x;
		}
		printf("parent: waiting..\n");
		wait(&status);
		printf("parent: status is %d\n", (status>>8)+powNum);
	}
	else if(pid == 0)
	{
		printf("child: bye!\n");
		exit(x+y);
	}

}
