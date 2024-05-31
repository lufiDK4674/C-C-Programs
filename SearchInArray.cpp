#include <stdio.h>
int main()
{
    int arr[5],key,found=0;

    printf("Enter 5 elements of the Array\n");
    for(int i=0;i<5;i++)
        scanf("%d",&arr[i]);
    printf("Enter the key to search\n");
    scanf("%d",&key);

    for(int i=0;i<5;i++)
    {
        if(arr[i]==key)
            found++;
    }
    if(found==0)
        printf("Element Not Found");
    else
        printf("Element found %d times",found);

    return 0;

}
