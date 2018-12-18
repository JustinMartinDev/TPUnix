//
// Created by ubuntu on 12/12/18.
//
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char* argv[]) {
    int     pipefd[2], nbytes;
    char    string[600];

    pipe(pipefd);

    int pidChild = fork();

    if(pidChild==0){
        close(pipefd[0]);    // close reading end in the child

        dup2(pipefd[1], 1);  // send stdout to the pipe
        dup2(pipefd[1], 2);  // send stderr to the pipe

        close(pipefd[1]);    // this descriptor is no longer needed

        execl("/bin/ls","ls","-l", (char*)NULL);
    } else {
        char buffer[1024];

        close(pipefd[1]);  // close the write end of the pipe in the parent

        while (read(pipefd[0], buffer, sizeof(buffer)) != 0) {
            printf("%s", buffer);
        }

    }
}