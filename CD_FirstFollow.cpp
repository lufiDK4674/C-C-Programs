#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTIONS 100
#define MAX_PRODUCTION_LENGTH 10

typedef struct
{
    char lhs;
    char rhs[MAX_PRODUCTION_LENGTH];
} Production;

Production grammar[MAX_PRODUCTIONS];
int num_productions = 0;

void findFirstpos(char symbol, int *firstpos, int *isProcessing)
{
    memset(firstpos, 0, 26 * sizeof(int));

    if (isProcessing[symbol - 'A'])
        return;                     // Avoid infinite recursion
    isProcessing[symbol - 'A'] = 1; // Mark this symbol as being processed

    for (int i = 0; i < num_productions; i++)
    {
        if (grammar[i].lhs == symbol)
        {
            if (grammar[i].rhs[0] >= 'a' && grammar[i].rhs[0] <= 'z')
            {
                firstpos[grammar[i].rhs[0] - 'a'] = 1;
            }
            else
            {
                int temp_firstpos[26] = {0};
                findFirstpos(grammar[i].rhs[0], temp_firstpos, isProcessing);
                for (int j = 0; j < 26; j++)
                {
                    if (temp_firstpos[j])
                        firstpos[j] = 1;
                }
            }
        }
    }

    isProcessing[symbol - 'A'] = 0; // Mark this symbol as no longer being processed
}

void findFollowpos(char symbol, int *followpos, int *isProcessing)
{
    memset(followpos, 0, 26 * sizeof(int));

    if (isProcessing[symbol - 'A'])
        return;                     // Avoid infinite recursion
    isProcessing[symbol - 'A'] = 1; // Mark this symbol as being processed

    // Special case: Add EOF symbol to FOLLOW set of start symbol
    if (symbol == 'S')
    {                             // Assuming 'S' is your start symbol
        followpos['$' - 'a'] = 1; // Assuming '$' represents EOF
    }

    for (int i = 0; i < num_productions; i++)
    {
        int len = strlen(grammar[i].rhs);
        for (int j = 0; j < len; j++)
        {
            if (grammar[i].rhs[j] == symbol)
            {
                if (j == len - 1 && grammar[i].lhs != symbol)
                {
                    int temp_followpos[26] = {0};
                    findFollowpos(grammar[i].lhs, temp_followpos, isProcessing);
                    for (int k = 0; k < 26; k++)
                    {
                        if (temp_followpos[k])
                            followpos[k] = 1;
                    }
                }
                else if (j < len - 1)
                {
                    int temp_firstpos[26] = {0};
                    findFirstpos(grammar[i].rhs[j + 1], temp_firstpos, isProcessing);
                    for (int k = 0; k < 26; k++)
                    {
                        if (temp_firstpos[k])
                            followpos[k] = 1;
                    }
                }
            }
        }
    }

    isProcessing[symbol - 'A'] = 0; // Mark this symbol as no longer being processed
}

int main()
{
    // Example symbol
    char symbol = 'S';

    // Add your grammar productions here
    strcpy(grammar[num_productions].rhs, "aBb");
    grammar[num_productions++].lhs = 'S';

    strcpy(grammar[num_productions].rhs, "cA");
    grammar[num_productions++].lhs = 'A';

    strcpy(grammar[num_productions].rhs, "d");
    grammar[num_productions++].lhs = 'B';

    int firstpos[26] = {0};
    int followpos[26] = {0};
    int isProcessingFirst[26] = {0};
    int isProcessingFollow[26] = {0};

    findFirstpos(symbol, firstpos, isProcessingFirst);
    findFollowpos(symbol, followpos, isProcessingFollow);

    printf("Firstpos for %c:\n", symbol);
    for (int i = 0; i < 26; i++)
    {
        if (firstpos[i])
            printf("%c ", 'a' + i);
    }
    printf("\n");

    printf("Followpos for %c:\n", symbol);
    for (int i = 0; i < 26; i++)
    {
        if (followpos[i])
            printf("%c ", 'a' + i);
    }
    printf("\n");

    return 0;
}
