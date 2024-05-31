#include <stdio.h>

int Divisor(int n)
{
    int div=0;
    for(int i=n; i>=1; i--)
    {
        if(n%i==0)
            div++;
    }
    return div;
}
int main()
{
    int div, opened=0, closed=0;
    for(int i=1; i<=100; i++)
    {
       div = Divisor(i);

       if(div%2==0)
        closed++;
       else
        opened++;
    }
    printf("closed : %d\n",closed);
    printf("opened : %d",opened);

    return 0;
}
