#include <stdio.h>

#define INF 9999

int main()
{
    int n, a[10][10];
    int i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);

            if(i != j && a[i][j] == 0)
                a[i][j] = INF;
        }
    }

    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(a[i][j] > a[i][k] + a[k][j])
                    a[i][j] = a[i][k] + a[k][j];
            }
        }
    }

    printf("\nShortest Distance Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
