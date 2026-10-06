#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = malloc(sizeof *p);

    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    *p = 25;
    printf("*p = %d\n", *p);

    free(p);
    p = NULL;

    return 0;
}
