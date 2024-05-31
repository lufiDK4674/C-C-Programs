#include <stdio.h>
int main()
{
    int arr[20][20],sparse[20][20],row=0,i,j,m,n;
    printf("Enter the no. of Rows & Column\n");
    scanf("%d%d",&m,&n);
    printf("Enter the Matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]!=0)
            {
                sparse[row][0]=i;
                sparse[row][1]=j;
                sparse[row][2]=arr[i][j];
                row++;
            }
        }
    }
    printf("The Sparse Matrix of the given Matrix is \n");

    for(i=0;i<row;i++)
    {
        for(j=0;j<3;j++)
            printf("%d\t",sparse[i][j]);
        printf("\n");
    }
    return 0;
}
