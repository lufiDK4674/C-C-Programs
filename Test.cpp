#include <stdio.h>
#include <stdbool.h>

struct Student {
    char name[30];
    char DOB[30];
    float Bio_marks;
    float Chem_marks;
};

typedef struct Student info;

void swap(info* xp, info* yp) {
    info temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void SortArray(info arr[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if ((arr[j].Bio_marks + arr[j].Chem_marks) > (arr[j + 1].Bio_marks + arr[j + 1].Chem_marks)) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int main() {
    info S1[100];
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("Enter details of the students:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: ");
        scanf(" %s", &S1[i].name);

        printf("DOB: ");
        scanf(" %s", &S1[i].DOB);

        printf("Biology marks: ");
        scanf("%f", &S1[i].Bio_marks);

        printf("Chemistry marks: ");
        scanf("%f", &S1[i].Chem_marks);

        printf("\n");
    }

    SortArray(S1, n);

    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", S1[i].name);
        printf("DOB: %s\n", S1[i].DOB);
        printf("Biology marks: %.2f\n", S1[i].Bio_marks);
        printf("Chemistry marks: %.2f\n", S1[i].Chem_marks);
        printf("\n");
    }

    return 0;
}
