#include <stdio.h>

int main(void) {
    int *p = NULL;

    if (p == NULL) {
        printf("p does not point to a valid object.\n");
    }

    return 0;
}
