#include <stdio.h>
#include <stdlib.h>

struct node_type
{
    int data;
    struct node_type* link;
};

typedef struct node_type node;
typedef node* list;


void PrintList(list head)
{
    list cur = head;
    printf("\n\nLinked List: ");
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->link;
    }
    printf("\n");
}
list create_list()
{
    char ch;
    list head = NULL;
    printf("Do you want to create a linked list (Y/N)? ");
    scanf(" %c", &ch);                                      // Add space before `%c` to consume newline character in input buffer

    if (ch == 'Y')
    {
        head = (list)malloc(sizeof(node));
        printf("Enter the data to be stored: ");
        scanf("%d", &(head->data));
        head->link = NULL;
        return head;
    }
    else if (ch == 'N')
    {
        printf("Exit\n");
        return NULL;
    }
    else
    {
        printf("Invalid input, program will exit\n");
        return NULL;
    }
}
list Insertion(list head)
{
    int pos;
    list current = head;

    printf("Where do you want to insert ? ");
    scanf(" %d", &pos);

    list temp=(list)malloc(sizeof(node));

    printf("Enter the data to be entered ");
    scanf(" %d",&(temp->data));

    temp->link=NULL;

    if(pos == 0)
    {
        temp->link = head;
        head = temp;
    }
    else
    {
        int counter = 1;
        while(current != NULL)
        {
            if(counter == pos)
            {
                temp->link = current->link;
                current->link = temp;
                break;
            }
            else
            {
                current=current->link;
                counter++;
            }
        }
        if(pos>counter)
            printf("Invalid Position \n EXIT \n");
    }
    return head;

}

list Deletion(list head)
{
    int key,deleted=0;
    list prev,cur;
    prev = NULL;
    cur = head;
    printf("Enter the data that you want to delete\t");
    scanf(" %d", &key);

    while(cur != NULL)
    {
        if(head->data == key)
        {
            head=head->link;
            cur=head;
            deleted = 1;
        }
        else if (cur->data == key)
        {
            prev->link=cur->link;
            cur=cur->link;
            deleted =1;
        }
        else
            {
                prev=cur;
                cur=cur->link;
            }
    }
    if(deleted=0)
        printf("Entered data is not present in the list \n");
    return head;
}
list Reverse(list head)
{
    list cur, prev, next;
    prev=NULL;
    cur=head;
    while(cur != NULL)
    {
        next=cur->link;
        cur->link=prev;
        prev=cur;
        cur=next;
    }
    head=prev;
    return head;
}

int main()
{
    list head = create_list();
    int choice;

    printf("\n Select the operation you want to perform \n");
    printf(" 1 : Insertion \n");
    printf(" 2 : Deletion \n");
    printf(" 3 : Reverse \n");
    printf(" Press any other key to exit \n ");
    scanf(" %d",&choice);

   while (choice == 1 || choice == 2 || choice == 3)
   {
    switch (choice)
    {
    case 1 :
        head = Insertion(head);
        PrintList(head);
        break;
    case 2 :
        head = Deletion(head);
        PrintList(head);
        break;
    case 3 :
        head = Reverse(head);
        PrintList(head);
        break;
    }
    printf("\n Select the operation you want to perform \n");
    printf(" 1 : Insertion \n");
    printf(" 2 : Deletion \n");
    printf(" 3 : Reverse \n");
    printf(" Press any other key to exit \n ");
    scanf(" %d",&choice);

   }

    return 0;
}
