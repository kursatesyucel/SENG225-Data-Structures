#include <stdio.h>

void printArray(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = (int)(sizeof(numbers) / sizeof(numbers[0]));

    printArray(numbers, size);

    return 0;
}
