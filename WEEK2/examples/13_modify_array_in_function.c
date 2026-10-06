#include <stdio.h>

void doubleValues(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

int main(void) {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = (int)(sizeof(numbers) / sizeof(numbers[0]));

    doubleValues(numbers, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
