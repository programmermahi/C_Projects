#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    char roll_no[20];
    char course[50];
    char class_name[20];
    char contact[20];
};

struct Student students[20];
int total = 0;

void enter() {
    int ch;
    printf("How many students do you want to enter? ");
    scanf("%d", &ch);

    for (int i = total; i < total + ch; i++) {
        printf("\nEnter the Data of student %d\n", i + 1);

        printf("Enter name: ");
        scanf("%s", students[i].name);

        printf("Enter Roll no: ");
        scanf("%s", students[i].roll_no);

        printf("Enter course: ");
        scanf("%s", students[i].course);

        printf("Enter class: ");
        scanf("%s", students[i].class_name);

        printf("Enter contact: ");
        scanf("%s", students[i].contact);
    }
    total += ch;
}

void show() {
    if (total == 0) {
        printf("No data is entered\n");
    } else {
        for (int i = 0; i < total; i++) {
            printf("\nData of Student %d\n", i + 1);
            printf("Name: %s\n", students[i].name);
            printf("Roll no: %s\n", students[i].roll_no);
            printf("Course: %s\n", students[i].course);
            printf("Class: %s\n", students[i].class_name);
            printf("Contact: %s\n", students[i].contact);
        }
    }
}

void search() {
    if (total == 0) {
        printf("No data is entered\n");
    } else {
        char roll_no[20];
        printf("Enter the roll no of student: ");
        scanf("%s", roll_no);

        for (int i = 0; i < total; i++) {
            if (strcmp(roll_no, students[i].roll_no) == 0) {
                printf("Name: %s\n", students[i].name);
                printf("Roll no: %s\n", students[i].roll_no);
                printf("Course: %s\n", students[i].course);
                printf("Class: %s\n", students[i].class_name);
                printf("Contact: %s\n", students[i].contact);
                return;
            }
        }
        printf("Student with roll no %s not found.\n", roll_no);
    }
}

void update() {
    if (total == 0) {
        printf("No data is entered\n");
    } else {
        char roll_no[20];
        printf("Enter the roll no of student which you want to update: ");
        scanf("%s", roll_no);

        for (int i = 0; i < total; i++) {
            if (strcmp(roll_no, students[i].roll_no) == 0) {
                printf("\nPrevious data\n");
                printf("Data of Student %d\n", i + 1);
                printf("Name: %s\n", students[i].name);
                printf("Roll no: %s\n", students[i].roll_no);
                printf("Course: %s\n", students[i].course);
                printf("Class: %s\n", students[i].class_name);
                printf("Contact: %s\n", students[i].contact);

                printf("\nEnter new data\n");
                printf("Enter name: ");
                scanf("%s", students[i].name);

                printf("Enter Roll no: ");
                scanf("%s", students[i].roll_no);

                printf("Enter course: ");
                scanf("%s", students[i].course);

                printf("Enter class: ");
                scanf("%s", students[i].class_name);

                printf("Enter contact: ");
                scanf("%s", students[i].contact);

                printf("Student data updated successfully.\n");
                return;
            }
        }
        printf("Student with roll no %s not found.\n", roll_no);
    }
}

void deleterecord() {
    if (total == 0) {
        printf("No data is entered\n");
    } else {
        int a;
        printf("Press 1 to delete all records\n");
        printf("Press 2 to delete a specific record\n");
        scanf("%d", &a);

        if (a == 1) {
            total = 0;
            printf("All records are deleted.\n");
        } else if (a == 2) {
            char roll_no[20];
            printf("Enter the roll no of the student you want to delete: ");
            scanf("%s", roll_no);

            for (int i = 0; i < total; i++) {
                if (strcmp(roll_no, students[i].roll_no) == 0) {
                    for (int j = i; j < total - 1; j++) {
                        students[j] = students[j + 1];
                    }
                    total--;
                    printf("Record deleted successfully.\n");
                    return;
                }
            }
            printf("Student with roll no %s not found.\n", roll_no);
        } else {
            printf("Invalid input\n");
        }
    }
}

int main() {
    int value;

    while (1) {
        printf("\nPress 1 to enter data\n");
        printf("Press 2 to show data\n");
        printf("Press 3 to search data\n");
        printf("Press 4 to update data\n");
        printf("Press 5 to delete data\n");
        printf("Press 6 to exit\n");
        scanf("%d", &value);

        switch (value) {
            case 1:
                enter();
                break;
            case 2:
                show();
                break;
            case 3:
                search();
                break;
            case 4:
                update();
                break;
            case 5:
                deleterecord();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid input\n");
                break;
        }
    }
}

