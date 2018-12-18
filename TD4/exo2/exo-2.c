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
    int     fd[2], nbytes;
    char    string[60];

    pipe(fd);

    int pidChild = fork();

    if(pidChild==0){
        close(fd[0]);
        dup(fd[1]);
        string = "It's value";
        printf("It's value");
    } else {
        close(fd[1]);
        dup(fd[0]);
        FILE *fptr = fdopen(fd[0],"r");

        if(fgets(string, 60, fptr)!=NULL)
            printf("Received string: %s\n", string);
    }
    return 0;
}
