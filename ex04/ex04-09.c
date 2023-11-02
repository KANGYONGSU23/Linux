#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	char buffer[1024];
	int nread;
	nread = readlink("test.txt", argv[1], 1024);
	write(1,argv[1],nread);
	printf("\n");
}
