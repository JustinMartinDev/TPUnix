//
// Created by ubuntu on 12/12/18.
//
#include <unistd.h>


int main(int argc, char* argv[]) {
    execl("/bin/ls", "ls", "-l", (char *)NULL);
    return 0;
}