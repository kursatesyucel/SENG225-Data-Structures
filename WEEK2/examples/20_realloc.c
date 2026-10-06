#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size = 5;
    int *numbers = malloc((size_t)size * sizeof *numbers);

    if (numbers == NULL) {
        return 1;
    }

    for (int i = 0; i < size; i++) {
        numbers[i] = i + 1;
    }

    int newSize = 10;
    int *temp = realloc(numbers, (size_t)newSize * sizeof *numbers);

    if (temp == NULL) {
        free(numbers);
        return 1;
    }

    numbers = temp;

    for (int i = size; i < newSize; i++) {
        numbers[i] = i + 1;
    }

    for (int i = 0; i < newSize; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);
    numbers = NULL;

    return 0;
}
