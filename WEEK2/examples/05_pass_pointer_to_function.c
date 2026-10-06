#include <stdio.h>

void change(int *p) {
    *p = 100;
}

int main(void) {
    int number = 10;

    printf("Before: number = %d\n", number);
    change(&number);
    printf("After : number = %d\n", number);

    return 0;
}
