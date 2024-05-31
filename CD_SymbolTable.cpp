#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SYMBOLS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    // Add other attributes as needed
} Symbol;

Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

bool insertSymbol(const char *name) {
    if (symbolCount >= MAX_SYMBOLS) {
        printf("Symbol table full\n");
        return false;
    }

    if (strlen(name) >= MAX_NAME_LENGTH) {
        printf("Symbol name too long\n");
        return false;
    }

    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            printf("Symbol %s already exists in the symbol table\n", name);
            return false;
        }
    }

    strcpy(symbolTable[symbolCount].name, name);
    symbolCount++;
    printf("Symbol %s inserted into symbol table\n", name);
    return true;
}

int main() {
   char symbolNames[MAX_NAME_LENGTH];
loop:
   printf("Enter symbol names (max %d length):\n", MAX_NAME_LENGTH);
   scanf("%s", symbolNames);
   insertSymbol(symbolNames);
goto loop;
    return 0;
}