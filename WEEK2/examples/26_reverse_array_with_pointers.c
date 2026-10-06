#include <stdio.h>

void reverse(int *arr, int size) {
    if (arr == NULL || size <= 1) {
        return;
    }

    int *left = arr;
    int *right = arr + size - 1;

    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

int main(void) {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = (int)(sizeof(numbers) / sizeof(numbers[0]));

    reverse(numbers, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
