#include <stdio.h>
#include <string.h>

#define NUM_STUDENTS 3

typedef struct {
    char name[50];
    float grade;
} Student;

int main() {
    Student students[NUM_STUDENTS];
    float sum = 0;
    int topIndex = 0;

    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter name of student %d: ", i + 1);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; 

        printf("Enter grade of %s: ", students[i].name);
        scanf("%f", &students[i].grade);
        getchar(); 

        sum += students[i].grade;

        if (students[i].grade > students[topIndex].grade) {
            topIndex = i;
        }
    }

    float average = sum / NUM_STUDENTS;

    printf("\nClass Average: %.2f\n", average);
    printf("Top Student: %s with grade %.2f\n", students[topIndex].name, students[topIndex].grade);

    return 0;
}
