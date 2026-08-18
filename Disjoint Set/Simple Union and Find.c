#include <stdio.h>

int parent[10];

// Make Set
void makeSet(int n)
{
    for(int i = 1; i <= n; i++)
        parent[i] = -1;
}

// Find
int find(int x)
{
    if(parent[x] == -1)
        return x;

    return find(parent[x]);
}

// Union
void unionSet(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);

    if(rootX != rootY)
        parent[rootX] = rootY;
}

int main()
{
    int n = 6;

    makeSet(n);

    unionSet(1, 2);
    unionSet(3, 4);
    unionSet(5, 6);

    printf("Root of 2 = %d\n", find(2));
    printf("Root of 3 = %d\n", find(3));
    printf("Root of 5= %d\n", find(5));

    return 0;
}
