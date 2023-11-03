#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main()
{
	printf("MYDATA=%s\n", getenv("MYDATA"));
	while(*environ)
		printf("%s\n", *environ++);
}
