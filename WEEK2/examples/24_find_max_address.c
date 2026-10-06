#include <stdio.h>

int *findMax(int *arr, int size) {
    if (arr == NULL || size <= 0) {
        return NULL;
    }

    int *max = arr;

    for (int i = 1; i < size; i++) {
        if (arr[i] > *max) {
            max = &arr[i];
        }
    }

    return max;
}

int main(void) {
    int numbers[] = {10, 40, 15, 80, 25};
    int size = (int)(sizeof(numbers) / sizeof(numbers[0]));

    int *result = findMax(numbers, size);

    if (result != NULL) {
        printf("Max value   = %d\n", *result);
        printf("Max address = %p\n", (void *)result);
    }

    return 0;
}
