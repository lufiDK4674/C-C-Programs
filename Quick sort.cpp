#include<stdio.h>
void swap(int*a,int*b)
{

    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int arr[],int low,int high)
{
    int pivot=arr[low];
    int i=low+1;
    int j=high;

    while(i<=j)

    {

        while(i<=high && arr[i]<=pivot)
            i++;
         while(j>=low && arr[j]>pivot)
            j--;
        if(i<j)
        swap(&arr[i],&arr[j]);
    }
swap(&arr[low],&arr[j]);
    return j;
}
void quickSort(int arr[],int low,int high)
{

    if(low<high)
    {

        int pivot_index=partition(arr,low,high);
        quickSort(arr,low,pivot_index-1);
          quickSort(arr,pivot_index+1,high);
    }
}
void printarray(int* A,int n)
{
    for(int i=0;i<n;i++)
        printf("%d\t",A[i]);
}
int main()
{

    int arr[50],i,n;
        printf("Enter size of array\n");
    scanf("%d",&n);
    printf("Enter the elements of array\n");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("\n The unsorted array is :\n");
    printarray(arr,n);
    quickSort(arr,0,n-1);
    printf("\n The sorted array is :\n");
    printarray(arr,n);
    return 0;
}

