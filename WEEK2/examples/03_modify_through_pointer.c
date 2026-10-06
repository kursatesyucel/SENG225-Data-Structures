#include <stdio.h>

int main(void) {
    int x = 10;
    int *p = &x;

    printf("Before: x = %d\n", x);

    *p = 50;

    printf("After : x = %d\n", x);

    return 0;
}
