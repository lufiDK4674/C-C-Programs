#include <stdio.h>

void PrintArray(int arr[], int n) {
    for (int j = 0; j < n; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");
}

void max_heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        max_heapify(arr, n, largest);
    }
}

int main() {
    int arr[50], n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements of the array: \n ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Array before heapify: ");
    PrintArray(arr, n);

    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(arr, n, i);
    }

    printf("Array after heapify: ");
    PrintArray(arr, n);

    return 0;
}
