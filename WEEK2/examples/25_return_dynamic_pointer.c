#include <stdio.h>
#include <stdlib.h>

int *createNumber(void) {
    int *p = malloc(sizeof *p);

    if (p == NULL) {
        return NULL;
    }

    *p = 10;
    return p;
}

int main(void) {
    int *number = createNumber();

    if (number == NULL) {
        return 1;
    }

    printf("%d\n", *number);

    free(number);
    number = NULL;

    return 0;
}
