#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool expression(const char **expr);
bool term(const char **expr);
bool factor(const char **expr);

bool factor(const char **expr) {
    if (isdigit(**expr)) { // Check if the current character is a digit
        // Loop to handle multi-digit numbers by advancing the pointer
        while(isdigit(**expr)) {
            (*expr)++;
        }
        return true;
    } else if (**expr == '(') { // Handle expressions within parentheses
        (*expr)++; // Move past the opening parenthesis
        if (!expression(expr)) {
            return false;
        }
        if (**expr == ')') {
            (*expr)++; // Move past the closing parenthesis
            return true;
        }
        return false; // Unmatched parentheses
    }
    return false; // Not a digit or parentheses, invalid factor
}

bool term(const char **expr) {
    if (!factor(expr)) {
        return false;
    }
    while (**expr == '*' || **expr == '/') { // Handle multiplication and division
        (*expr)++; // Move past the operator
        if (!factor(expr)) {
            return false;
        }
    }
    return true;
}

bool expression(const char **expr) {
    if (!term(expr)) {
        return false;
    }
    while (**expr == '+' || **expr == '-') { // Handle addition and subtraction
        (*expr)++; // Move past the operator
        if (!term(expr)) {
            return false;
        }
    }
    return true;
}

int main() {
    char input[100];
loop:
    printf("Enter an expression: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0'; // Remove the trailing newline

        const char *expr = input;
        if (expression(&expr) && *expr == '\0') { // Ensure entire input is consumed
            printf("Valid expression\n");
        } else {
            printf("Invalid expression\n");
        }
    } else {
        printf("Error reading input\n");
    }
goto loop;
    return 0;
}
