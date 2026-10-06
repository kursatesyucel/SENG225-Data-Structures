#include <stdio.h>

void change(int x) {
    x = 100;
    printf("Inside change(): x = %d\n", x);
}

int main(void) {
    int number = 10;

    printf("Before function: number = %d\n", number);
    change(number);
    printf("After function : number = %d\n", number);

    return 0;
}
