#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main(void) {
    struct Node *head = malloc(sizeof *head);
    struct Node *second = malloc(sizeof *second);

    if (head == NULL || second == NULL) {
        free(head);
        free(second);
        return 1;
    }

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = NULL;

    printf("%d -> %d -> NULL\n", head->data, head->next->data);

    free(second);
    free(head);

    return 0;
}
