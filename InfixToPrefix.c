#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_type
{
    char data;
    struct node_type* link;
};
typedef struct node_type node;
typedef node* list;

int Precedence(char operator)
{
    if(operator== '+'||operator=='-')
        return 1;
    else if(operator=='*'||operator=='/')
        return 2;
    else if (operator=='^')
        return 3;
    else
        return -1;
}

    // created an empty stack
list top1 = NULL;
list top2 = NULL;

list Push(list top, char data)
{
            list temp = (list)malloc(sizeof(node));
            temp->data = data;
            temp->link = top;
            top = temp;
            temp = NULL;
            return top;
}

list Pop(list top)
 {
    printf("%c", top->data);
    top = top->link;
    return top;
}

void InfixToPrefix(char* A, int n)
{
    for(int i=n;i>=0;i--)
    {
        if(A[i]==')')
          top1= Push(top1,A[i]);

        else if (A[i]=='+'|| A[i]=='-'|| A[i]=='*' || A[i]== '/' || A[i]=='^')      // for operators
        {
            while(top1!=NULL && Precedence(A[i])<=Precedence(top1->data))
            {
                top2 = Push(top2,top1->data);
                top1 = top1->link;
            }
            top1 = Push(top1, A[i]);
        }
        else if(A[i]=='(')                                                          // for ')'
        {
            while(top1->data!=')' && top1 != NULL)
               {
                   top2 = Push(top2,top1->data);
                   top1 = top1->link;
               }

            if(top1->data==')' && top1 != NULL)
                top1=top1->link ;                                                     //Discarding '('
        }
        else
        top2 = Push(top2, A[i]);
    }
     while (top1 != NULL) 
        {
        top2 = Push(top2, top1->data);
        top1 = top1->link;
        }

        while (top2 != NULL) 
        {
        top2 = Pop(top2);
        }
}
int main()
{
    char infix[50];
    printf("Enter the infix expression: ");
    scanf(" %s", infix);
    int len = strlen(infix);
    printf("Prefix : ");
    InfixToPrefix(infix, len );
}
