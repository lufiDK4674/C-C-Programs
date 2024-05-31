#include <stdio.h>
#include <string.h>

void StringFinder(char* str1, char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);

    for(int i = 0; i <= m - n; i++) {
        int j;
        for(j = 0; j < n; j++) {
            if(str2[j] != str1[i + j])
                break;
        }
        if(j == n)
        {
          printf("%s is found at index %d of %s\n", str2, i, str1);
          i+=(n+1);
        }
    }

    printf("%s is not found in %s\n", str2, str1);
}

int main() {
    char String[100], input[100];
    printf("Enter the String: ");
    scanf("%s", String);
    printf("Enter the input String: ");
    scanf("%s", input);

    StringFinder(String, input);
    return 0;
}
