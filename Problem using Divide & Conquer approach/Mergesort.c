#include <stdio.h>

// Function to merge two sorted subarrays
void merge(int a[], int low, int mid, int high)
{
    int i = low;         // Starting index of left subarray
    int j = mid + 1;     // Starting index of right subarray
    int k = low;         // Starting index of temporary array
    int temp[100];

    // Compare elements from both subarrays
    while (i <= mid && j <= high)
    {
        // If left element is smaller
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
        }
        // If right element is smaller
        else
        {
            temp[k] = a[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements from left subarray
    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements from right subarray
    while (j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    // Copy sorted elements back to original array
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i];
    }
}


// Function to divide the array
void mergeSort(int a[], int low, int high)
{
    // Continue dividing until one element remains
    if (low < high)
    {
        // Find middle position
        int mid = (low + high) / 2;

        // Sort left half
        mergeSort(a, low, mid);

        // Sort right half
        mergeSort(a, mid + 1, high);

        // Merge the two sorted halves
        merge(a, low, mid, high);
    }
}


int main()
{
    int n, i;

    // Read number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    // Read array elements
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Call Merge Sort
    mergeSort(a, 0, n - 1);

    // Display sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
