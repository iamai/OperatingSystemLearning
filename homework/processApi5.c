#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {

    int p = fork();
    if (p < 0) {
        fprintf(stderr, "some error happen");
        exit(1);
    } else if (p == 0) {
        printf("I am the child %d\n", getpid());

        int w = wait(NULL);
        printf("hello%d\n", w);

        printf("child end\n");
    } else {
        printf("I am the parert of %d\n", p);
        printf("goodbye\n");

        printf("parent end\n");
    }

    return 0;
}