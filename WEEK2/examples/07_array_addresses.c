#include <stdio.h>

int main(void) {
    int numbers[5] = {10, 20, 30, 40, 50};

    printf("numbers      = %p\n", (void *)numbers);
    printf("&numbers[0]  = %p\n", (void *)&numbers[0]);

    for (int i = 0; i < 5; i++) {
        printf("&numbers[%d] = %p, value = %d\n",
               i, (void *)&numbers[i], numbers[i]);
    }

    return 0;
}
