#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {

    int p = fork();
    int pipeN[2];
    if (pipe(pipeN) < 0) {
        exit(1);
    }


    if (p < 0) {
        fprintf(stderr, "some error happen");
        exit(1);
    } else if (p == 0) {
        printf("I am the child %d\n", getpid());
        printf("hello\n");

        pipeN[0] == stdin;

        printf("child end\n");
    } else {
        printf("I am the parert of %d\n", p);
        
        int p2 = fork();
        if (p2 == 0) {
            printf("I am the child2 %d\n", getpid());
            printf("hello2\n");

            pipeN[1] = stdout;

            printf("child2 end\n");
        } else {
            printf("I am the parert2 of %d\n", p2);
            printf("parent2 end %d\n");
        }

        printf("parent end %d\n");
    }

    return 0;
}