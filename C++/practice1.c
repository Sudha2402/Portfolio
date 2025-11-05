#include <stdio.h>
#include <math.h>

int countDigit(int num)
{
    if (num < 0)
    {
        num = -num;
    }
    else if (num == 0)
    {
        return 1;
    }
    int count = 0;
    while (num > 0)
    {
        num /= 10;
        count++;
    }

    return count;
}

int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d", &n);

    int digits = countDigit(n);
    // printf("%d\n", digits);

    int subtractor = pow(10, digits) - 1;

    int result = subtractor - n;
    printf("%d\n", result);

    printf("%d\n", result);
    printf("%x\n", 54554);

    return 0;
}