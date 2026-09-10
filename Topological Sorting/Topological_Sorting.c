#include <stdio.h>

int main() {
    int n, i, j, top = -1;
    int graph[10][10], visited[10] = {0};
    int stack[10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)  {
        for(j = 0; j < n; j++)   {
            scanf("%d", &graph[i][j]);
        }
    }
// DFS function using recursion
    void DFS(int v)
    {
        int j;
        visited[v] = 1;

        // Visit all connected vertices
        for(j = 0; j < n; j++) {
            if(graph[v][j] == 1 && visited[j] == 0) {
                DFS(j);
            }
        }

        // Add vertex to stack after visiting all neighbours
        stack[++top] = v;
    }
 // Perform DFS for all vertices
    for(i = 0; i < n; i++) {
        if(visited[i] == 0) {
            DFS(i);
        }
    }

    printf("Topological Sort: ");

    // Print stack in reverse order
    while(top >= 0)  {
        printf("%d ", stack[top--]);
    }

    return 0;
}
