#include <stdio.h>
#include <limits.h>

// A utility function to get sum of array elements freq[i] to freq[j]
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

// A utility function to get the optimal binary search tree cost
int optimalSearchTreeCost(int keys[], int freq[], int n) {
    // Create an auxiliary 2D table to store results of subproblems
    int cost[n][n];

    // For a single key, cost is equal to frequency of the key
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // Now consider chains of length 2, 3, ... . L is chain length.
    for (int L = 2; L <= n; L++) {
        // i is row number in cost[][]
        for (int i = 0; i <= n - L + 1; i++) {
            // Get column number j from row number i and chain length L
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            // Try making all keys in interval keys[i..j] as root
            for (int r = i; r <= j; r++) {
                // c = cost when keys[r] becomes root of this subtree
                int c = ((r > i) ? cost[i][r - 1] : 0) + ((r < j) ? cost[r + 1][j] : 0) + sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    return cost[0][n - 1];
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n], freq[n];

    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &keys[i]);

    printf("Enter the frequencies:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &freq[i]);

    printf("Cost of Optimal BST is %d\n", optimalSearchTreeCost(keys, freq, n));
    return 0;
}
