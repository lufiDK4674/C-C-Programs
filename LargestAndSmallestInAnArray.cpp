#include <stdio.h>
int main()
{
    int arr[5],smallest,Largest;

    printf("Enter 5 elements of the Array\n");
    for(int i=0;i<5;i++)
        scanf("%d",&arr[i]);

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4-i;j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
        printf("\nLargest Number is %d\t", arr[4]);
        printf("\nSmallest Number is %d\t", arr[0]);
    return 0;
}
