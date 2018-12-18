//
// Created by ubuntu on 28/11/18.
//
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char* argv[]){
    int pidChild = fork();

    if(pidChild != 0){
        printf("Hello I am the parent process, my process id is %d, my parent’s id is %d, and I am the parent of process %d.\n", getpid(), getppid(), pidChild);
    }
     else {
        printf("Hello I am the child process, my process id is %d, and my parent’s id is %d.\n", getpid(), getppid());
    }
    int returnStatus;
    waitpid(pidChild, &returnStatus, 0);
    return 0;
}