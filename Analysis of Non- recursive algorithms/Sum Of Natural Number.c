#include <stdio.h>

int main()
{
    int n,sum=0;
    
    printf("Enter a Number: ");
    scanf("%d",&n);
    sum=((n*(n+1))/2);
    printf("The Number %d Sum of Natural is : %d",n,sum);

    return 0;
}
