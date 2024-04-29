#include <stdio.h>
#include <string.h>
// Function to find the length of the longest common subsequence
int lcsLength(char *X, char *Y)
 {
    int m = strlen(X);
    int n = strlen(Y);
    int L[m + 1][n + 1];
    int i, j;

    // Building the L[m+1][n+1] table in a bottom-up manner
    for (i = 0; i <= m; i++)
 {
        for (j = 0; j <= n; j++)
 {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }
    return L[m][n];
}
int main() {
    char X[] = "GOLDEN";
    char Y[] = "ELDER";
    printf("Length of LCS is %d\n", lcsLength(X, Y));
    return 0;
}