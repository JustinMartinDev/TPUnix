//
// Created by ubuntu on 03/12/18.
//

//
// Created by ubuntu on 28/11/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    int pidChild = fork();

    int filefd = open("output.txt", O_WRONLY|O_CREAT, 0666);
null
    if(pidChild==0){
        close(1);
        dup(filefd);
        printf("Hello World");
    } else {
        close(filefd);
        wait(NULL);
    }
    return 0;
}
