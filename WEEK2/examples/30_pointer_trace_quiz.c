#include <stdio.h>

int main(void) {
    int x = 10;
    int *p = &x;
    int **q = &p;

    printf("x    = %d\n", x);
    printf("&x   = %p\n", (void *)&x);
    printf("p    = %p\n", (void *)p);
    printf("*p   = %d\n", *p);
    printf("&p   = %p\n", (void *)&p);
    printf("q    = %p\n", (void *)q);
    printf("*q   = %p\n", (void *)*q);
    printf("**q  = %d\n", **q);

    return 0;
}
