//
// Created by ubuntu on 28/11/18.
//
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>


static int[3][3] *rptr;

int main(int argc, char* argv[]){

    rptr = mmap(NULL, sizeof(rptr), PROT_READ | PROT_WRITE,
                MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    rptr[0][0] = 1; //a
    rptr[0][1] = 1; //b
    rptr[0][2] = 0; //ab

    rptr[1][0] = 1; //c
    rptr[1][1] = 1; //d
    rptr[1][2] = 0; //cd

    rptr[2][0] = 1; //e
    rptr[2][1] = 1; //f
    rptr[2][2] = 0; //ef


/*    pid_t childPID;
    for(i=0; i<3; i++, childPID=fork()){
        if(childPID==0)
            *(rptr+((i+2)*sizeof(int))) = *(rptr+(i*sizeof(int))) + *(rptr+((i+1)*sizeof(int)))
        else
            wait(childPID);
    }*/
    /*int childPid = fork();

    if(childPid!=0){
        wait(childPid);
        double result = (rptr->ab*rptr->cd)/(rptr->ef)
        printf("Result = %lf", result);
    } else {
        rptr->ab = a+b;
        printf("Child pid : %d result a+b = %lf", getpid(), rptr->ab);
    }*/
//    printf("%d", *ab);
    munmap(rptr, sizeof(rptr));
    return 0;
}