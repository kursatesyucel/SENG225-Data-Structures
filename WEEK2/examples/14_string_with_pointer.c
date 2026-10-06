#include <stdio.h>

int main(void) {
    char name[] = "Hello";
    char *p = name;

    while (*p != '\0') {
        printf("%c\n", *p);
        p++;
    }

    return 0;
}
