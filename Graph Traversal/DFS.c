#include <stdio.h>

int graph[10][10], visited[10], n;

void DFS(int start)
{
    int stack[10], top = -1;
    int i, v;

    stack[++top] = start;

    while (top != -1)
    {
        v = stack[top--];

        if (visited[v] == 0)
        {
            printf("%d ", v);
            visited[v] = 1;

            for (i = n - 1; i >= 0; i--)
            {
                if (graph[v][i] == 1 && visited[i] == 0)
                {
                    stack[++top] = i;
                }
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);

    return 0;
}