#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    printf("Number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int *numbers = malloc((size_t)n * sizeof *numbers);

    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        numbers[i] = i * 10;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);
    numbers = NULL;

    return 0;
}
