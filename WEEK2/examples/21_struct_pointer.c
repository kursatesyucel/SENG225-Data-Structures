#include <stdio.h>

struct Student {
    int id;
    float grade;
};

int main(void) {
    struct Student student;
    struct Student *p = &student;

    p->id = 101;
    p->grade = 90.5f;

    printf("ID    : %d\n", p->id);
    printf("Grade : %.2f\n", p->grade);

    return 0;
}
