//
// Created by ubuntu on 10/12/18.
//
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>


void sighandler(int);

int main(int argc, char* argv[]){
    int childPID = fork();

    if(childPID==0){
        signal(SIGUSR1, sighandler);
        while(1) {
            printf("Going to sleep for a second...\n");
            sleep(1);
        }
    }
    else {
        sleep(2);
        kill(childPID, SIGUSR1);
    }
    return 0;
}

void sighandler(int signum) {
    printf("Caught signal %d, coming out...\n", signum);
    exit(1);
}