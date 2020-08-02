#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    int p = fork();
    if (p < 0) {
        fprintf(stderr, "some error happen");
        exit(1);
    } else if (p == 0) {
        printf("I am the child %d\n", getpid());

        char *args[] = {"./test", "2" "23"};
        execv("./test", args);

        printf("child end\n");
    } else {
        printf("I am the parert of %d\n", p);
        printf("parent end\n");
    }

    return 0;
}