#include <stdio.h>
#include <string.h>

/*This Program is a simulation of a DFA that accepts all the strings ending with 1 */
void DFA(char* input)
{
    int n = strlen(input);
    char State = 'A';
    for(int i = 0; i < n; i++)
    {
        if(input[i] == '1' && State == 'A')
            State = 'B';
        else if(input[i] == '0' && State == 'B')
            State = 'A';
    }
    if(State == 'B')
        printf("String Accepted\n");
    else if(State == 'A')
        printf("String Rejected\n");
}

int main()
{
    char String[100];
    printf("Enter the input String: ");
    scanf(" %s", String);
    DFA(String);
    return 0;
}
