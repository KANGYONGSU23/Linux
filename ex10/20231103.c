#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int num = 0;
void int_handle(int);

int main()
{
	static struct sigaction act;
	
	void int_handle(int);

	act.sa_handler = int_handle;
	sigfillset(&(act.sa_mask));
	sigaction(SIGINT, &act, NULL);
	
	sleep(10);
}

void int_handle(int signum)
{
	printf("\nprocess closed..\n");
}
