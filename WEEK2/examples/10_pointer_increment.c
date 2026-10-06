#include <stdio.h>

int main(void) {
    int numbers[5] = {10, 20, 30, 40, 50};
    int *p = numbers;

    for (int i = 0; i < 5; i++) {
        printf("Address: %p, Value: %d\n", (void *)p, *p);
        p++;
    }

    return 0;
}
