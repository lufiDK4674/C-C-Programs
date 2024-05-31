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
list top = NULL;

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
    printf("%c",top->data);
    top=top->link;
    return top;
}


void InfixToPostfix(char*A, int n)
{
    for(int i=0; i< n; i++)
    {
        // check the type of the character being read
        if(A[i]=='(')                                                              //for '('
         top = Push(top,'(');

        else if (A[i]=='+'|| A[i]=='-'|| A[i]=='*' || A[i]== '/' || A[i]=='^')      // for operators
        {
            while(Precedence(A[i])<=Precedence(top->data))
            {
                top = Pop(top);
            }
            top = Push(top, A[i]);
        }
        else if(A[i]==')')                                                          // for ')'
        {
            while(top->data!='(')
               top = Pop(top);

            if(top->data=='(')
                top=top->link ;                                                     //Discarding '('
        }
        else
        printf("%c", A[i]);
    }
}

int main()
{
    char infix[50];
    printf("Enter the infix expression in (): \n");
    scanf(" %s", infix);
    int len = strlen(infix);
    printf("Postfix : ");
    InfixToPostfix(infix, len );
}
