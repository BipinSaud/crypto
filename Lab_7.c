/*7. WAP to find modular inverse of input integer in mod n.*/
#include <stdio.h>

// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

// Function to find the modular inverse of a under modulo n
int modInverse(int a, int n)
{
    int x, y;
    int gcd = gcdExtended(a, n, &x, &y);

    // If a and n are not coprime, the modular inverse does not exist
    if (gcd != 1)
    {
        printf("Modular inverse does not exist.\n");
        return -1;
    }
    else
    {
        // x might be negative, so take it positive
        int result = (x % n + n) % n;
        return result;
    }
}

int main()
{
    int a, n;
    printf("Enter an integer a: ");
    scanf("%d", &a);
    printf("Enter modulus n: ");
    scanf("%d", &n);

    int inverse = modInverse(a, n);
    if (inverse != -1)
    {
        printf("The modular inverse of %d under modulo %d is %d\n", a, n, inverse);
    }

    return 0;
}
