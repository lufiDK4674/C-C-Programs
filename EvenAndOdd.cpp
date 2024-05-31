#include <stdio.h>
int main()
{
    int arr[50],even=0,odd=0,i,n;

    printf("Enter the size of the array\n");
    scanf("%d",&n);

    printf("Enter %d elements of the Array\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
    {
        if(arr[i]%2==0)
            even++;
        else
            odd++;
    }
        printf("No. of even elements are %d \n",even);
        printf("No. of odd elements are %d \n",odd);

    return 0;
}
