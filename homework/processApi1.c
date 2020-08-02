#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int x = 100;

    int p = fork();
    if (p < 0) {
        fprintf(stderr, "some error happen");
        exit(1);
    } else if (p == 0) {
        printf("I am the child %d, x=%d", getpid(), x);
        x = 101;
        printf("child change the x=%d", x);
    } else {
        printf("I am the parnert of %d, x=%d", p, x);
        x = 102;
        printf("parent change the x=%d", x);
    }

    return 0;
}