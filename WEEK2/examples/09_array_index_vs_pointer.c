#include <stdio.h>

int main(void) {
    int numbers[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++) {
        printf("numbers[%d] = %d, *(numbers + %d) = %d\n",
               i, numbers[i], i, *(numbers + i));
    }

    return 0;
}
