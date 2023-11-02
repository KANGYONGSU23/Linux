#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char *files[] = {"a.txt", "b.txt", "c.txt"};
    int num_files = sizeof(files) / sizeof(char*);

    for(int i=0; i<num_files; i++) {
        pid_t pid = fork();

        if(pid == 0) { // child process
            execl("/bin/wc", "wc", files[i], (char *)0);
            perror("execl failed");
            exit(1);
        } else if(pid > 0) { // parent process
            wait(NULL); // wait for child to finish
        } else { // fork failed
            perror("fork failed");
            exit(1);
        }
    }

    return 0;
}
