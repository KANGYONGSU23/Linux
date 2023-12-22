#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int fd

void* thread_routine(void *arg){
	write(fd, buf, strlen(buf));
}

int main() {
	int fd = open("./file.txt",O_RDWR|O_CREAT,0644);
	
	if(fd==-1){
		perror("file open fall");
		return 1;
	}

	if(close(fd)==-1){
		perror("file close fall");
		return 1;
	}

	return 0;
}

