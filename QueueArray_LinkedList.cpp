#include <stdio.h>
#include <stdlib.h>

int Queue[10], queueFront= 0,queueRear=-1, maxsize=10;

void enqueueArray()
{
    if (queueRear >= maxsize-1)
        printf("queue Overflow\n");
    else
    {
        printf("Enter the data ");
        queueRear++;
        scanf(" %d", &Queue[queueRear]);
    }
}
void dequeueArray()
{
    if(queueFront > queueRear)
    {
        printf("queue Underflow \n");
    }
    else
        printf("%d is dequeued\n", Queue[queueFront++]);
}
void PrintQueueArray()
{
    printf("\n\nQueue: ");
    for(int i=queueFront;i<=queueRear;i++)
    {
        printf(" %d ",Queue[i]);
    }
}


struct queue_node
{
    int data;
    struct queue_node* link;
};

typedef struct queue_node qnode;
typedef qnode* list;

list enqueueLL(list rear)
{
    list temp = (list)malloc(sizeof(qnode));
    printf("Enter the data ");
    scanf(" %d",&(temp->data));
    temp->link=NULL;
    rear->link = temp;
    rear=temp;
    return rear;
}
list dequeueLL(list front)
{
    if(front==NULL)
    {
        printf("queue Underflow");
        return NULL;
    }
    printf("\n %d is dequeued", front->data);
    front=front->link;
    return front;
}
void PrintList(list front)
{
    list cur = front;
    printf("\n\nqueue: ");
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->link;
    }
    printf("\n");
}
int main()
{
    int choice, ch;
    printf("\nWhich type of queue do you want to create?\n");
    printf(" 1. Using Array\n");
    printf(" 2. Using Linked List\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("\nWhich operation do you want to perform?\n");
            printf(" 1. enqueue\n");
            printf(" 2. dequeue\n");
            scanf("%d", &ch);

            while(ch==1||ch==2)
            {
                switch (ch)
                {
                case 1:
                    enqueueArray();
                    PrintQueueArray();
                    break;
                case 2:
                    dequeueArray();
                    PrintQueueArray();
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
            break;

        case 2:

            list front = (list)malloc(sizeof(qnode));
            printf("Enter data \n");
            scanf(" %d", &(front->data));
            front->link = NULL;
            list rear = front;

            printf("\nWhich operation do you want to perform?\n");
            printf(" 1. enqueue\n");
            printf(" 2. dequeue\n");
            scanf(" %d", &ch);

            while(ch==1||ch==2)
            {
                switch (ch)
            {
                case 1:
                    rear = enqueueLL(rear);
                    PrintList(front);
                    break;
                case 2:
                    front = dequeueLL(front);
                    PrintList(front);
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
            }
            printf("\nWhich operation do you want to perform?\n");
            printf(" 1. enqueue\n");
            printf(" 2. dequeue\n");
            scanf(" %d", &ch);
            }
            break;
    }

    return 0;
}

