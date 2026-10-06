#include <stdio.h>

int main(void) {
    int x = 10;
    int *p = &x;
    int **pp = &p;

    printf("x    = %d\n", x);
    printf("*p   = %d\n", *p);
    printf("**pp = %d\n", **pp);

    **pp = 50;

    printf("After **pp = 50, x = %d\n", x);

    return 0;
}
