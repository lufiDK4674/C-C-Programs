#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SYMBOLS 100
#define MAX_PRODUCTIONS 100

typedef struct
{
    char lhs[MAX_PRODUCTIONS];
    char rhs[MAX_PRODUCTIONS][MAX_SYMBOLS];
} Prod;

bool usefulProds[MAX_PRODUCTIONS] = {false};

void RemoveUseless(Prod *G, int startProd, int n)
{
    if (usefulProds[startProd])
        return;
    usefulProds[startProd] = true;

    // Mark productions reachable from this rule as useful
    for (size_t j = 0; j < strlen(G->rhs[startProd]); j++)
    {
        char symbol = G->rhs[startProd][j];
        for (int i = 0; i < n; i++)
            if (G->lhs[i] == symbol)
                RemoveUseless(G, i, n);
    }
}

int main()
{
    Prod g;
    int n, i;
    printf("Enter the number of productions : ");
    scanf("%d", &n);
    printf("Enter the productions without / \n");
    for (i = 0; i < n; i++)
    {
        printf("Production %d LHS > Enter > RHS :\n", i + 1);
        scanf(" %c", &g.lhs[i]);
        scanf(" %s", g.rhs[i]);
    }

    // Display the productions
    for (i = 0; i < n; i++)
        printf("%d: %c -> %s\n", i + 1, g.lhs[i], g.rhs[i]);

    int startIdx;
    for (int i = 0; i < n; i++)
    {
        if (g.lhs[i] == 'S')
        {
            startIdx = i;
            break;
        }
    }
    RemoveUseless(&g, startIdx, n);

    printf("Reduced Grammar :\n");

    for (int i = 0; i < n; i++)
    {
        if (usefulProds[i])
        {
            printf("%d: %c -> %s\n", i + 1, g.lhs[i], g.rhs[i]);
        }
    }
    return 0;
}
