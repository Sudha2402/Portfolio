#include <stdio.h>

int Prime(int n)
{
    if (n <= 1)
    {
        printf("not prime nor composite");
        return 0;
    }
    if (n == 2) //smallest must be checked
    {
        printf("prime");
        return 0;
    }

    // prime or not
    // for (int i = 2; i <= n / 2; i++)
    for (int i = 2; i * i <= n; i++) // Faster check
    {

        if (n % i == 0)
        {
            printf("not prime\n");
            // continue;

            return 0; // Exit the entire function early

            //  break;         // Exit the loop early //if no function the use break
        }
    }

    printf("prime\n");

    return 1;
}

int main()
{
    // sum of first natural number
    int n;
    printf("Enter a number to sum upto:");
    scanf("%d", &n);
    int result = n * (n + 1) / 2;
    printf("%d\n", result);

    // sum of first natural number
    int result2 = 0;
    for (int i = 1; i <= n; i++)
    {
        result2 += i;
    }

    printf("%d\n", result2);

    int intisprime = Prime(n);

    // other method to get prime or not:

    int is_prime = 1; // Assume prime initially
    
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            is_prime = 0; // Mark as not prime
            break;        // Exit the loop early
        }
    }

    if (is_prime)
        printf("Prime\n");
    else
        printf("Not prime\n");











    return 0;
}