#include <stdio.h>
#include <stdlib.h>

int Stack[10], stackTop=-1, maxsize=10,counter = 0;

void pushArray()
{
    if (stackTop >= maxsize-1)
        printf("Stack Overflow\n");
    else
    {
        printf("Enter the data ");
        stackTop++;
        scanf(" %d", &Stack[stackTop]);
        counter++;
    }
}
int popArray()
{
    if(stackTop==-1)
    {
        printf("Stack Underflow \n");
        return -1;
    }
    else
        {
            return Stack[stackTop--];
            counter--;
        }

}
void PrintStackArray()
{
    printf("\n\nStack: ");
    for(int i=counter-1;i>=0;i--)
    {
        printf(" %d ",Stack[i]);
    }
}

struct stack_node
{
    int data;
    struct stack_node* link;
};

typedef struct stack_node snode;
typedef snode* list;

list pushLL(list top)
{
    list temp = (list)malloc(sizeof(snode));
    printf("Enter the data ");
    scanf(" %d",&(temp->data));
    temp->link = top;
    top=temp;
    return top;
}
list popLL(list top)
{
    if(top==NULL)
    {
        printf("Stack Underflow");
        return NULL;
    }
    else
    {
        printf("\n %d is popped", top->data);
        top=top->link;
        return top;
    }
}
void PrintList(list top)
{
    list cur = top;
    printf("\n\nStack: ");
    while (cur!= NULL)
    {
        printf("%d ", cur->data);
        cur = cur->link;
    }
    printf("\n");
}

int main()
{
    int choice, ch;
    printf("\nWhich type of stack do you want to create?\n");
    printf(" 1. Using Array\n");
    printf(" 2. Using Linked List\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("\nWhich operation do you want to perform?\n");
            printf(" 1. Push\n");
            printf(" 2. Pop\n");
            scanf("%d", &ch);

            while(ch==1||ch==2)
            {
                switch (ch)
                {
                case 1:
                    pushArray();
                    PrintStackArray();
                    break;
                case 2:
                    printf("%d is popped\n", popArray());
                    PrintStackArray();
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
                }
            printf("\nWhich operation do you want to perform?\n");
            printf(" 1. Push\n");
            printf(" 2. Pop\n");
            scanf("%d", &ch);
            }
            break;

        case 2:
            list top=NULL;
            top = (list)malloc(sizeof(snode));
            printf("Enter data \n");
            scanf(" %d", &(top->data));
            top->link = NULL;

            printf("\nWhich operation do you want to perform?\n");
            printf(" 1. Push\n");
            printf(" 2. Pop\n");
            scanf(" %d", &ch);

            while(ch==1||ch==2)
            {
                switch (ch)
            {
                case 1:
                    top = pushLL(top);
                    PrintList(top);
                    break;
                case 2:
                    top = popLL(top);
                    PrintList(top);
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
            }
            printf("\nWhich operation do you want to perform?\n");
            printf(" 1. Push\n");
            printf(" 2. Pop\n");
            scanf(" %d", &ch);
            }
            break;
    }

    return 0;
}
