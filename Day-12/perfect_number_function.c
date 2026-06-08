/*Write a program to write a function for checking a perfect number */
#include <stdio.h>
void perfect(int n);
int main()
{
    int n;
    printf("Enter the number u want to check for :");
    scanf("%d", &n);
    perfect(n);
    return 0;
}
void perfect(int n)
{
    int i, sum = 0;
    if (n == 0)
    {
        printf("0 is not a perfect number ");
    }
    else
    {
        for (i = 1; i < n; i++)
        {
            if (n % i == 0)
            {
                sum += i;
            }
        }
        if (n == sum)
        {
            printf("Entered number %d is a perfect number ", n);
        }
        else
        {
            printf("Entered number %d is not a perfect number ", n);
        }
    }
}