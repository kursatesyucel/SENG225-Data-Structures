#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    printf("How many numbers? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    double *numbers = malloc((size_t)n * sizeof *numbers);

    if (numbers == NULL) {
        return 1;
    }

    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        printf("numbers[%d] = ", i);

        if (scanf("%lf", &numbers[i]) != 1) {
            free(numbers);
            return 1;
        }

        sum += numbers[i];
    }

    printf("Average = %.2f\n", sum / n);

    free(numbers);
    numbers = NULL;

    return 0;
}
