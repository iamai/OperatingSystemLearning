#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    FILE *fp;
    char buff[255];
    fp = fopen("testFile", "w+");

    int p = fork();
    if (p < 0) {
        fprintf(stderr, "some error happen");
        exit(1);
    } else if (p == 0) {
        printf("I am the child %d\n", getpid());

        fscanf(fp, "%s", buff);
        printf("%s\n", buff);
        fclose(fp);

        printf("child end\n");
    } else {
        printf("I am the parert of %d\n", p);

        fscanf(fp, "%s", buff);
        printf("%s\n", buff);
        fclose(fp);

        printf("parent end\n");
    }

    return 0;
}