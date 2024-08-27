/*8.WAP to calculate the Euler totient function of input integer.*/
#include <stdio.h>

// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// A simple method to evaluate Euler Totient Function
int phi(unsigned int n)
{
    unsigned int result = 1; // Start with result = 1 because gcd(n, n) is 1
    for (int i = 2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}

// Function to print the numbers relatively prime to n
void printRelativelyPrimeNumbers(int n)
{
    printf("Numbers relatively prime to %d: ", n);
    for (int i = 1; i < n; i++)
    {
        if (gcd(i, n) == 1)
            printf("%d ", i);
    }
    printf("\n");
}

// Driver program to test the above functions
int main()
{
    int n;
    printf("Enter an integer n: ");
    scanf("%d", &n);

    printf("ϕ(%d) = %d\n", n, phi(n));
    printRelativelyPrimeNumbers(n);

    return 0;
}
