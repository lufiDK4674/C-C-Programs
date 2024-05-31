#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEYWORD_COUNT 32
#define MAX_KEYWORD_LENGTH 20
#define MAX_INPUT_LENGTH 1024
#define MAX_TOKENS 1000

// List of keywords
const char *keywords[MAX_KEYWORD_COUNT] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

// Function to check if a character is an operator
bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' ||
           ch == '=' || ch == '<' || ch == '>' || ch == '!' || ch == '&' || ch == '?' || ch == ':';
}

// Function to check if a string is a number (constant)
bool isNumber(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

// Function to check if a string is a valid identifier
bool isIdentifier(char *str)
{
    if (!isalpha(str[0]) && str[0] != '_')
    { // Identifier must start with an alphabet or underscore
        return false;
    }

    for (int i = 1; str[i] != '\0'; i++)
    {
        if (!isalnum(str[i]) && str[i] != '_')
        { // Subsequent characters can be alphanumeric or underscore
            return false;
        }
    }
    return true;
}

// Function to check if a string is a keyword
bool isKeyword(char *str)
{
    for (int i = 0; i < MAX_KEYWORD_COUNT; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

// Arrays to store tokens
char keywords_arr[MAX_TOKENS][MAX_KEYWORD_LENGTH];
char identifiers_arr[MAX_TOKENS][MAX_KEYWORD_LENGTH];
char constants_num_arr[MAX_TOKENS][MAX_KEYWORD_LENGTH];
char constants_str_arr[MAX_TOKENS][MAX_KEYWORD_LENGTH];
char operators_arr[MAX_TOKENS];
char comments_arr[MAX_INPUT_LENGTH];
char unrecognized_arr[MAX_TOKENS];

int num_keywords = 0;
int num_identifiers = 0;
int num_constants_num = 0;
int num_constants_str = 0;
int num_operators = 0;
int num_comments = 0;
int num_unrecognized = 0;

// Lexer function to tokenize the input
void lexer(char *source)
{
    char buffer[256];
    int index = 0;

    for (int i = 0; source[i] != '\0'; i++)
    {
        char currentChar = source[i];

        // Ignore whitespace
        if (isspace(currentChar))
        {
            continue;
        }

        // Single-line comment
        if (currentChar == '/' && source[i + 1] == '/')
        {
            i += 2; // Skip the "//"
            int j = 0;
            while (source[i] != '\0' && source[i] != '\n')
            {
                comments_arr[num_comments] = source[i];
                i++;
                j++;
            }
            comments_arr[num_comments + j] = '\0';
            num_comments++;
            continue;
        }

        // Multi-line comment
        if (currentChar == '/' && source[i + 1] == '*')
        {
            i += 2; // Skip the "/*"
            int j = 0;
            while (source[i] != '\0' && !(source[i] == '*' && source[i + 1] == '/'))
            {
                comments_arr[num_comments + j++] = source[i++];
            }
            i++; // Skip past the '/'
            comments_arr[num_comments + j++] = '*';
            comments_arr[num_comments + j++] = '/';
            comments_arr[num_comments + j] = '\0';
            num_comments++;
            continue;
        }

        // Operator
        if (isOperator(currentChar))
        {
            operators_arr[num_operators++] = currentChar;
            continue;
        }

        // Number (Constant)
        if (isdigit(currentChar))
        {
            buffer[index++] = currentChar;
            while (isdigit(source[i + 1]))
            {
                buffer[index++] = source[++i];
            }
            buffer[index] = '\0'; // Null-terminate the string
            strcpy(constants_num_arr[num_constants_num++], buffer);
            index = 0; // Reset buffer index
            continue;
        }

        // String literal
        if (currentChar == '"')
        {
            i++; // Skip the opening quote
            index = 0;
            while (source[i] != '\0' && source[i] != '"')
            {
                buffer[index++] = source[i++];
            }
            buffer[index] = '\0';
            if (source[i] == '"')
            {
                strcpy(constants_str_arr[num_constants_str++], buffer);
            }
            else
            {
                printf("<Unterminated string literal>\n");
            }
            continue;
        }

        // Identifier or keyword
        if (isalpha(currentChar) || currentChar == '_')
        {
            buffer[index++] = currentChar;
            while (isalnum(source[i + 1]) || source[i + 1] == '_')
            {
                buffer[index++] = source[++i];
            }
            buffer[index] = '\0'; // Null-terminate the string
            if (isKeyword(buffer))
            {
                strcpy(keywords_arr[num_keywords++], buffer);
            }
            else if (isIdentifier(buffer))
            {
                strcpy(identifiers_arr[num_identifiers++], buffer);
            }
            else
            {
                printf("Invalid identifier: %s\n", buffer);
            }
            index = 0; // Reset buffer index
            continue;
        }

        // Unrecognized character
        unrecognized_arr[num_unrecognized++] = currentChar;
    }
}

// Function to print tokens
void printTokens()
{
    printf("Keywords:   ");
    for (int i = 0; i < num_keywords; i++)
    {
        printf("%s  ", keywords_arr[i]);
    }

    printf("\nIdentifiers:  ");
    for (int i = 0; i < num_identifiers; i++)
    {
        printf("%s  ", identifiers_arr[i]);
    }

    printf("\nConstants (Numbers):  ");
    for (int i = 0; i < num_constants_num; i++)
    {
        printf("%s  ", constants_num_arr[i]);
    }

    printf("\nConstants (Strings):  ");
    for (int i = 0; i < num_constants_str; i++)
    {
        printf("%s  ", constants_str_arr[i]);
    }

    printf("\nOperators:    ");
    for (int i = 0; i < num_operators; i++)
    {
        printf("%c  ", operators_arr[i]);
    }

    printf("\nComments: ");
    for (int i = 0; i < num_comments; i++)
    {
        printf("%s  ", comments_arr + i);
    }
    printf("\nUnrecognized characters:  ");
    for (int i = 0; i < num_unrecognized; i++)
    {
        printf("%c  ", unrecognized_arr[i]);
    }
}
int main()
{
    char input[MAX_INPUT_LENGTH];
    printf("Enter the source code: ");
    if (fgets(input, MAX_INPUT_LENGTH, stdin) != NULL)
    {
        lexer(input);
        printTokens();
    }
    else
    {
        printf("Error reading input\n");
    }
    return 0;
}