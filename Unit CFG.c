#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTIONS 10
#define MAX_SYMBOLS 10

typedef struct
{
  char lhs[MAX_PRODUCTIONS];
  char rhs[MAX_PRODUCTIONS][MAX_SYMBOLS];
} Prod;

void RemoveUnit(Prod *G, int n)
{
  for (int i = 0; i < n; i++)
  {
    if (strlen(G->rhs[i]) == 1 && isupper(G->rhs[i][0]))
    {
      for (int j = 0; j < n; j++)
        if (G->rhs[i][0] == G->lhs[j])
          strcpy(G->rhs[i], G->rhs[j]);
    }
  }
}

int main()
{
  Prod g;
  int n, i;
  printf("Enter the number of productions: ");
  scanf("%d", &n);
  printf("Enter the %d productions LHS > Enter > RHS without spaces :\n",n);
  for (i = 0; i < n; i++)
  {
    printf("Production %d : \n", i + 1);
    scanf(" %c", &g.lhs[i]);
    scanf(" %s", g.rhs[i]);
  }

  // Display the productions
  for (i = 0; i < n; i++)
  {
    printf("%d: %c -> %s\n", i + 1, g.lhs[i], g.rhs[i]);
  }

  RemoveUnit(&g, n);

  printf("Reduced Grammar:\n");

  for (i = 0; i < n; i++)
  {
    printf("%d: %c -> %s\n", i + 1, g.lhs[i], g.rhs[i]);
  }

  return 0;
}
