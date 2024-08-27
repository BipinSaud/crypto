/*6. WAP to find the GCD the gcd of two input integer using Euclidean Algorithm.*/
#include <stdio.h>

// Recursive function to find GCD using Euclidean Algorithm and print steps
int euclidean_algorithm(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        printf("%d = %d * %d + %d\n", a, b, a / b, a % b);
        return euclidean_algorithm(b, a % b);
    }
}

int main()
{
    int a, b;

    printf("Enter two numbers a and b: ");
    scanf("%d %d", &a, &b);

    // Swap values if b is greater than a
    if (b > a)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    printf("Steps to find GCD of %d and %d:\n", a, b);
    int gcd = euclidean_algorithm(a, b);
    printf("GCD of %d and %d is %d\n", a, b, gcd);

    if (gcd == 1)
    {
        printf("Numbers %d %d are relatively prime\n", a, b);
    }
    else
    {
        printf("Numbers %d %d are not relatively prime\n", a, b);
    }

    return 0;
}
