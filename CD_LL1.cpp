#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTIONS 100
#define MAX_RHS_LENGTH 20
#define NUM_NON_TERMINALS 5
#define NUM_TERMINALS 4

// Structure to represent a production rule
typedef struct {
    char lhs;
    char rhs[MAX_RHS_LENGTH];
} Production;

// Productions in the grammar
Production productions[MAX_PRODUCTIONS];
int num_productions = 0;

// LL(1) parsing table
int LL1Table[NUM_NON_TERMINALS][NUM_TERMINALS];

// Utility function to find the index of a non-terminal in the table
int getNonTerminalIndex(char symbol) {
    switch (symbol) {
        case 'S': return 0;
        case 'A': return 1;
        case 'B': return 2;
        case 'C': return 3;
        case 'D': return 4;
        default: return -1;
    }
}

// Utility function to find the index of a terminal in the table
int getTerminalIndex(char symbol) {
    switch (symbol) {
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        default: return -1;
    }
}

// Construct the LL(1) parsing table
// Construct the LL(1) parsing table
void constructLL1Table() {
    // Initialize the table with -1 (no production)
    for (int i = 0; i < NUM_NON_TERMINALS; i++) {
        for (int j = 0; j < NUM_TERMINALS; j++) {
            LL1Table[i][j] = -1;
        }
    }

    // Populate the table based on the productions
    for (int i = 0; i < num_productions; i++) {
        char lhs = productions[i].lhs;
        char rhs = productions[i].rhs[0];
        int lhs_index = getNonTerminalIndex(lhs);
        int rhs_index = isalpha(rhs) ? getTerminalIndex(rhs) : -1;

        if (lhs_index != -1 && rhs_index != -1) {
            LL1Table[lhs_index][rhs_index] = i;
        }
    }
}

// LL(1) parsing function
void LL1Parse(char *input) {
    int input_len = strlen(input);
    char stack[input_len + 1];
    int top = 0;

    // Push the start symbol onto the stack
    stack[top++] = 'S';

    int input_index = 0;

    while (top > 0) {
        char top_symbol = stack[top - 1];

        // If the top symbol is a terminal, compare it with the current input symbol
        if (isalpha(top_symbol) && islower(top_symbol)) {
            if (input[input_index] == top_symbol) {
                top--;
                input_index++;
            } else {
                printf("Error: Unexpected symbol %c\n", input[input_index]);
                return;
            }
        }
        // If the top symbol is a non-terminal, use the LL1Table to find the corresponding rule
        else {
            int lhs_index = getNonTerminalIndex(top_symbol);
            int rhs_index = getTerminalIndex(input[input_index]);

            if (lhs_index == -1 || rhs_index == -1) {
                printf("Error: Invalid symbol in input or grammar\n");
                return;
            }

            int production_index = LL1Table[lhs_index][rhs_index];

            if (production_index == -1) {
                printf("Error: No production found for %c -> %c\n", top_symbol, input[input_index]);
                return;
            }

            top--;

            // Push the RHS symbols onto the stack in reverse order
            int rhs_len = strlen(productions[production_index].rhs);
            for (int i = rhs_len - 1; i >= 0; i--) {
                stack[top++] = productions[production_index].rhs[i];
            }
        }
    }

    if (input_index == input_len) {
        printf("Input string '%s' accepted\n", input);
    } else {
        printf("Error: Input string '%s' rejected\n", input);
    }
}


int main() {
    // Define your grammar productions here
    // Assuming the productions are correctly defined for the grammar
    // Make sure to define productions that correspond to an LL(1) grammar

    strcpy(productions[num_productions++].rhs, "aAb");
    productions[num_productions - 1].lhs = 'S';

    strcpy(productions[num_productions++].rhs, "cC");
    productions[num_productions - 1].lhs = 'A';

    strcpy(productions[num_productions++].rhs, "d");
    productions[num_productions - 1].lhs = 'C';

    strcpy(productions[num_productions++].rhs, "bD");
    productions[num_productions - 1].lhs = 'B';

    strcpy(productions[num_productions++].rhs, "a");
    productions[num_productions - 1].lhs = 'D';

    // Print the productions
    printf("Grammar:\n");
    printf("S -> aAb\n");
    printf("A -> cC\n");
    printf("C -> d\n");
    printf("B -> bD\n");
    printf("D -> a\n");
loop:
    // Construct the LL(1) parsing table based on the given grammar
    constructLL1Table();

    // Define the input string to be parsed
    char input[20];

    printf("\nEnter the input string to parse: ");
    scanf("%s", input);


    // Parse the input string using the LL(1) parsing method
    LL1Parse(input);
goto loop;

    return 0;
}
