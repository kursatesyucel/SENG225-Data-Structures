#include <stdio.h>

int add(int a, int b);

int main(void) {
    int result = add(10, 20);

    printf("10 + 20 = %d\n", result);

    return 0;
}

int add(int a, int b) {
    return a + b;
}
