#include <stdio.h>

void reverseArray(int *arr, int size) {
    if (size <= 1) return;
    int *left = arr;
    int *right = arr + size - 1;
    while (left < right) {
        int temp = *left;
        *left++ = *right;
        *right-- = temp;
    }
}

int main(void) {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = (int)(sizeof numbers / sizeof numbers[0]);
    reverseArray(numbers, size);
    for (int i = 0; i < size; ++i) printf("%d%s", numbers[i], i == size-1 ? "\n" : " ");
    return 0;
}
