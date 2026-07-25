#include <stdio.h>

int main()
{
    int i,n,Fact=1;
    
    printf("Enter a Number: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        Fact=Fact*i;
    }
    printf("The Factorial of %d is : %d",n,Fact);

    return 0;
}
