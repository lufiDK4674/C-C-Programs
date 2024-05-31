#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void NFA(char* input, int random)
{
    int n = strlen(input);
    char State = 'A';
    int j = 0;

    for (int i = 0; i < n; i++)
    {

        while (true)
        {
            if (input[i] == '1' && State == 'A')
            {
                if (random % 2 == 0)
                {
                    State = 'B';
                    break;
                }
                else
                {
                    random = randomNumber();
                    j++;
                }
            }
            else if (input[i] == '0' && State == 'B')
            {
                if (random % 2 == 0)
                {
                    State = 'A';
                    break;
                }
                else
                {
                    random = randomNumber();
                    j++;
                }
            }
            else
            {
                break;
            }
        }
    }

    if (State == 'B' && input[n - 1] == '1')
        printf("String Accepted\n");
    else
        printf("String Rejected\n");
}

int randomNumber()
{
    srand(time(NULL));
    return rand();
}

int main()
{
    char String[100];
    printf("Enter the input String: ");
    scanf("%s", String);
    int random = randomNumber();
    NFA(String, random);
    return 0;
}
