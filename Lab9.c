/*9.WAP to test if an input is prime or not using little Fermat's Theorem.*/
#include <stdio.h>
#include <stdlib.h>

// Function to compute x^y under modulo m
int power(int x, unsigned int y, unsigned int m)
{
    int result = 1; // Initialize result
    x = x % m;      // Update x if it is more than or equal to m

    if (x == 0)
        return 0; // In case x is divisible by m;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            result = (result * x) % m;

        // y must be even now
        y = y >> 1;      // y = y/2
        x = (x * x) % m; // Change x to x^2
    }
    return result;
}

// Function to test if n is prime using Fermat's little theorem
int isPrime(unsigned int n, int k)
{
    // Corner cases
    if (n <= 1 || n == 4)
        return 0;
    if (n <= 3)
        return 1;

    // Try k times
    while (k > 0)
    {
        // Pick a random number in [2..n-2]
        // Above corner cases make sure that n > 4
        int a = 2 + rand() % (n - 4);

        // Fermat's little theorem
        if (power(a, n - 1, n) != 1)
            return 0;

        k--;
    }

    return 1;
}

int main()
{
    int n;     // Number to test for primality
    int k = 5; // Number of iterations

    printf("Enter a number to check if it is prime: ");
    scanf("%d", &n);

    if (isPrime(n, k))
        printf("%d is prime\n", n);
    else
        printf("%d is not prime\n", n);

    return 0;
}
