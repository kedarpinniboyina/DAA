#include <stdio.h>

int main()
{
    int n, i, j, count = 0;
    int graph[10][10], indegree[10] = {0};
    int queue[10], front = 0, rear = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", 
            &graph[i][j]);

            if(graph[i][j] == 1)
                indegree[j]++;
        }
    }
    // Add vertices with indegree 0 to queue
    for(i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
            queue[rear++] = i;
    }

    printf("Topological Sort: ");
    // Process vertices in queue
    while(front < rear)
    {
        // Remove a vertex from queue
        int v = queue[front++];
        printf("%d ", v);
        count++;
        // Check all vertices connected from v
        for(j = 0; j < n; j++)
        {
            if(graph[v][j] == 1)
            {
                // Remove the edge by decreasing indegree
                indegree[j]--;
                
                // If indegree becomes 0, add vertex to queue
                if(indegree[j] == 0)
                    queue[rear++] = j;
            }
        }
    }
    
    return 0;
}
