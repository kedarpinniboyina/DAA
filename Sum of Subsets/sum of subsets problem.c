#include <stdio.h>

int a[10], n, target, x[10];

void sum(int i, int currentSum)
{
    int j;

    if (currentSum == target)
    {
        printf("{ ");
        for (j = 0; j < n; j++)
            if (x[j] == 1)
                printf("%d ", a[j]);
        printf("}\n");
        return;
    }

    if (i == n || currentSum > target)
        return;

    x[i] = 1;
    sum(i + 1, currentSum + a[i]);

    x[i] = 0;
    sum(i + 1, currentSum);
}

int main()
{
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("Subsets are:\n");
    sum(0, 0);

    return 0;
}