#include <stdio.h>

int Queue[10], front = 0, rear = -1, maxsize = 10;

void enqueue()
{
    if ((front == 0 && rear == maxsize - 1) || (rear == front - 1 && rear > -1))
        printf("\n Queue Overflow\n");
    else
    {
        rear = ++rear % maxsize;
        printf("Enter the data  ");
        scanf(" %d", &Queue[rear]);
    }
}
void dequeue()
{
    if (rear == -1)
        printf("\nQueue Underflow\n");
    else
    {
        printf(" %d is dequeued \n", Queue[front]);
        if (front != rear)
            front = ++front % maxsize;
        else
        {
            front = 0;
            rear = -1;
        }
    }
}
int main()
{
    int ch;
    printf("\nWhich operation do you want to perform?\n");
    printf(" 1. enqueue\n");
    printf(" 2. dequeue\n");
    scanf("%d", &ch);

    while (ch == 1 || ch == 2)
    {
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
        printf("\nWhich operation do you want to perform?\n");
        printf(" 1. enqueue\n");
        printf(" 2. dequeue\n");
        scanf("%d", &ch);
    }
}
