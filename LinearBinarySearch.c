#include <stdio.h>
#define MAX_SIZE 100

void linear_search(int *A, int size, int search_key)
{
    int index[MAX_SIZE];
    int found = 0;

    for (int i = 0; i < size; i++)
    {
        if (A[i] == search_key)
        {
            index[found] = i;
            found++;
        }
    }

    if (found == 0)
    {
        printf("The search key was not found.\n");
    }
    else
    {
        printf("The elements found %d times at index: ",found);
        for (int i = 0; i < found; i++)
            printf("%d, ", index[i]);
        printf("\n");
    }
}

void binary_search(int *A, int size, int search_key)
{
    int index[MAX_SIZE];
    int found = 0;
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (A[mid] == search_key)
        {
            index[found] = mid;
            found++;
        }

        if (A[mid] < search_key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (found == 0)
    {
        printf("The search key was not found.\n");
    }
    else
    {
        printf("The elements found %d times at index: ",found);
        for (int i = 0; i < found; i++)
            printf("%d, ", index[i]);
        printf("\n");
    }
}

int main()
{
    int arr[MAX_SIZE];
    int n, key;



    int choice;
    printf("Which search algorithm do you want to use?\n 1. Linear Search\n 2. Binary Search\nEnter your choice: ");
    scanf("%d", &choice);



    switch (choice)
    {
    case 1:
        printf("Enter the number of elements: ");
        scanf("%d", &n);

        printf("Enter the %d elements: ", n);
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        printf("Enter the key you want to search: ");
        scanf("%d", &key);

        linear_search(arr, n, key);
        break;
    case 2:
        printf("Enter the number of elements: ");
        scanf("%d", &n);

        printf("Enter the %d elements of Sorted Array: ", n);
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        printf("Enter the key you want to search: ");
        scanf("%d", &key);
        binary_search(arr, n, key);
        break;
    default:
        printf("Invalid choice.\n");
        return 1;
    }

    return 0;
}
