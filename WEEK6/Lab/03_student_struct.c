#include <stdio.h>

struct Student {
    int id;
    char name[30];
    float grade;
};

int main(void) {
    struct Student students[] = {
        {101, "Ali", 75.5f}, {102, "Ayse", 92.0f}, {103, "Mehmet", 68.5f}
    };
    int count = (int)(sizeof students / sizeof students[0]);
    int bestIndex = 0;
    for (int i = 0; i < count; i++) {
        printf("%d - %s - %.1f\n", students[i].id, students[i].name, students[i].grade);
        if (students[i].grade > students[bestIndex].grade) bestIndex = i;
    }
    struct Student *ptr = &students[0];
    printf("Pointer access: %s / %s\n", ptr->name, (*ptr).name);
    printf("Highest grade: %s (%.1f)\n", students[bestIndex].name, students[bestIndex].grade);
    return 0;
}
