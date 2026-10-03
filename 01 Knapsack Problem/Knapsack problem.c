#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, W, i, w;
    int weight[20], profit[20];
    int dp[20][50];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights: ");
    for(i = 1; i <= n; i++)
        scanf("%d", &weight[i]);

    printf("Enter profits: ");
    for(i = 1; i <= n; i++)
        scanf("%d", &profit[i]);

    printf("Enter capacity: ");
    scanf("%d", &W);

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if(i == 0 || w == 0)
                dp[i][w] = 0;

            else if(weight[i] <= w)
                dp[i][w] = max(profit[i] + dp[i-1][w-weight[i]],
                                dp[i-1][w]);

            else
                dp[i][w] = dp[i-1][w];
        }
    }

    printf("Maximum profit = %d\n", dp[n][W]);

    return 0;
}
