#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[]){
        int fd;
        char buffer[1024];
	int nread, cnt, numChar = 0;

	if (argc < 2)
		return 0;
	if((fd = open(argv[1], O_RDONLY)) == -1)
	{
		printf("file open error\n");
		return 0;
	}

	while((nread = read(fd, buffer, 1024))>0)
	{
		for(cnt =0; cnt < nread;cnt++)
		{
			if(buffer[cnt] >= 'a' && buffer[cnt] <= 'z'){
				numChar++;
			}
			else if (buffer[cnt] >= 'A' && buffer[cnt] <= 'Z'){
				numChar++;
				buffer[cnt] -= 'a' - 'A';
			}
		}
		lseek(fd, (off_t)-nread, SEEK_CUR);
		write(fd, buffer, nread);
	}

	close(fd);
	printf("n\n");
	printf("%s\n",buffer);
}
