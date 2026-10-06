#include <stdio.h>

int sum(const int *arr, int size) {
    int total = 0;

    for (int i = 0; i < size; i++) {
        total += *(arr + i);
    }

    return total;
}

int main(void) {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = (int)(sizeof(numbers) / sizeof(numbers[0]));

    printf("Sum = %d\n", sum(numbers, size));

    return 0;
}
