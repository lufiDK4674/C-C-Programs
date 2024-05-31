#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isValidIdentifier(char* str) {
    if (!isalpha(str[0]) && str[0] != '_') {
        return false;
    }
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return false;
        }
    }
    return true;
}

int main() {
    char identifier[100];
loop:
    printf("Enter an identifier: ");
    scanf("%s", identifier);
    if (isValidIdentifier(identifier)) {
        printf("Valid identifier\n");
    } else {
        printf("Invalid identifier\n");
    }
goto loop;
    return 0;
}
