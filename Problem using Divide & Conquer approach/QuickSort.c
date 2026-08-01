#include <stdio.h>

// Function to partition the array
int partition(int a[], int lb, int ub)
{
    int Start = lb;          // Start points to first element
    int End = ub;            // End points to last element
    int pivot = a[lb];       // Take first element as pivot
    int temp;

    // Continue until Start and End cross each other
    while(Start < End)
    {
        // Move Start until element greater than pivot is found
        while(a[Start] <= pivot)
        {
            Start++;
        }

        // Move End until element smaller than or equal to pivot is found
        while(a[End] > pivot)
        {
            End--;
        }

        // Swap elements if Start is before End
        if(Start < End)
        {
            temp = a[Start];
            a[Start] = a[End];
            a[End] = temp;
        }
    }

    // Place pivot in its correct position
    temp = a[lb];
    a[lb] = a[End];
    a[End] = temp;

    // Return pivot position
    return End;
}


// Function to perform Quick Sort
void Quick_sort(int a[], int lb, int ub)
{
    // Check if more than one element is present
    if(lb < ub)
    {
        // Partition the array and get pivot position
        int res = partition(a, lb, ub);

        // Sort left side of pivot
        Quick_sort(a, lb, res - 1);

        // Sort right side of pivot
        Quick_sort(a, res + 1, ub);
    }
}


int main()
{
    int i, n;

    // Read size of array
    printf("Enter the Size of Array: ");
    scanf("%d", &n);

    int a[n];

    // Read array elements
    printf("Enter the Elements:");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Call Quick Sort
    Quick_sort(a, 0, n - 1);

    // Display sorted array
    printf("Sorted Array is:");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    return 0;
}
