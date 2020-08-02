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
        printf("hello\n");

        close(STDOUT_FILENO);

        printf("child end\n");
    } else {
        printf("I am the parert of %d\n", p);
        printf("goodbye\n");

        int stat_val;
        int w = waitpid(p, &stat_val, 0);

        printf("parent end %d\n", w);
    }

    return 0;
}