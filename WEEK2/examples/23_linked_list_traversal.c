#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main(void) {
    struct Node *first = malloc(sizeof *first);
    struct Node *second = malloc(sizeof *second);
    struct Node *third = malloc(sizeof *third);

    if (first == NULL || second == NULL || third == NULL) {
        free(first);
        free(second);
        free(third);
        return 1;
    }

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    struct Node *current = first;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    free(third);
    free(second);
    free(first);

    return 0;
}
