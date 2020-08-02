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

        write(pipeN[1], "test message", sizeof(input));

        printf("child end\n");
    } else {
        printf("I am the parert of %d\n", p);

        wait(NULL);
        
        int p2 = fork();
        if (p2 == 0) {
            printf("I am the child2 %d\n", getpid());
            printf("hello2\n");

            char output[40];
            read(pipeN[0], output, sizeof(output));
            printf("message is : %s\n", output);

            printf("child2 end\n");
        } else {
            printf("I am the parert2 of %d\n", p2);
            
            wait(NULL);

            printf("parent2 end\n");
        }

        printf("parent end\n");
    }

    return 0;
}