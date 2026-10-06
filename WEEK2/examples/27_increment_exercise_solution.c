#include <stdio.h>

void increment(int *number) {
    if (number != NULL) {
        (*number)++;
    }
}

int main(void) {
    int x = 10;

    increment(&x);

    printf("%d\n", x);

    return 0;
}
