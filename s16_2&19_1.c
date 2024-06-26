#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices

// Function to check if the current vertex can be added to the Hamiltonian cycle
bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    // Check if the current vertex is adjacent to the last vertex added to the path
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }

    // Check if the current vertex has not already been included in the path
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

// Function to recursively find a Hamiltonian cycle starting from the vertex v
bool hamiltonianCycleUtil(bool graph[V][V], int path[], int pos) {
    // Base case: If all vertices are included in the path
    if (pos == V) {
        // Check if the last vertex is adjacent to the first vertex to form a cycle
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true; // Hamiltonian cycle found
        } else {
            return false;
        }
    }

    // Try different vertices as the next vertex in the path
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur to find the next vertex in the path
            if (hamiltonianCycleUtil(graph, path, pos + 1)) {
                return true;
            }

            // If adding vertex v doesn't lead to a solution, backtrack
            path[pos] = -1;
        }
    }

    return false;
}

// Function to find a Hamiltonian cycle in the graph
bool hamiltonianCycle(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++) {
        path[i] = -1; // Initialize path array
    }
    path[0] = 0; // Start from vertex 0

    if (!hamiltonianCycleUtil(graph, path, 1)) {
        printf("No Hamiltonian cycle exists in the graph.\n");
        return false;
    }

    printf("Hamiltonian cycle found: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]); // Print the first vertex again to form a cycle
    return true;
}

int main() {
    // Sample graph represented as an adjacency matrix
    bool graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCycle(graph);

    return 0;
}
