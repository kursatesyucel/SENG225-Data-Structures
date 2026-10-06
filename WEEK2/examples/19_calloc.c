#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 5;
    int *numbers = calloc((size_t)n, sizeof *numbers);

    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);
    numbers = NULL;

    return 0;
}
