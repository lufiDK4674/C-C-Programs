#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/*
    Check if a string belongs to the grammar:
    Expression -> Term {+ Term}
    Term -> Factor {* Factor}
    Factor -> 'a' | '(' Expression ')'
*/

// Function prototypes
bool isExpression(const char **ptr);
bool isTerm(const char **ptr);
bool isFactor(const char **ptr);
bool match(char expected, const char **ptr);

bool isExpression(const char **ptr) {
    const char *start = *ptr;
    if (isTerm(ptr)) {
        if (**ptr == '+') {
            (*ptr)++;
            return isExpression(ptr);
        }
        return true;
    }
    *ptr = start; // Reset on failure
    return false;
}

bool isTerm(const char **ptr) {
    const char *start = *ptr;
    if (isFactor(ptr)) {
        if (**ptr == '*') {
            (*ptr)++;
            return isTerm(ptr);
        }
        return true;
    }
    *ptr = start; // Reset on failure
    return false;
}

bool isFactor(const char **ptr) {
    if (match('a', ptr)) {
        return true;
    } else if (match('(', ptr)) {
        if (isExpression(ptr) && match(')', ptr)) {
            return true;
        }
    }
    return false;
}

bool match(char expected, const char **ptr) {
    if (**ptr == expected) {
        (*ptr)++;
        return true;
    }
    return false;
}

int main() {
    char input[100];
    printf("Grammar: \n");
    printf(" E -> E + T | T \n T -> T * F | F \n F -> ( E ) | a \n");
    printf("Enter an expression: ");
    if (fgets(input, sizeof(input), stdin)) {
        input[strcspn(input, "\n")] = 0; // Remove newline

        const char *ptr = input;
        if (isExpression(&ptr) && *ptr == '\0') {
            printf("The string belongs to the grammar.\n");
        } else {
            printf("The string does not belong to the grammar.\n");
        }
    } else {
        printf("Error reading input.\n");
    }
    return 0;
}
