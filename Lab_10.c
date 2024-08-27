/*10.WAP to simulate Diffie-Hellman Key Exchange Algorithm.*/
#include <stdio.h>

// Function to perform modular exponentiation
// It returns (a^b) % P
long long int power(long long int a, long long int b, long long int P)
{
    long long int result = 1;
    a = a % P; // Update 'a' if it is more than or equal to P

    while (b > 0)
    {
        // If b is odd, multiply 'a' with the result
        if (b % 2 == 1)
            result = (result * a) % P;

        // b must be even now
        b = b >> 1;      // b = b/2
        a = (a * a) % P; // Change 'a' to 'a^2'
    }
    return result;
}

// Driver program
int main()
{
    long long int P, G, x, a, y, b, ka, kb;

    // Prompt the user to enter the value of P
    printf("Enter the value of P (a prime number): ");
    scanf("%lld", &P);

    // Prompt the user to enter the value of G
    printf("Enter the value of G (a primitive root of P): ");
    scanf("%lld", &G);

    // Alice will choose the private key a
    printf("Enter the private key a for Alice: ");
    scanf("%lld", &a);
    x = power(G, a, P); // gets the generated key

    // Bob will choose the private key b
    printf("Enter the private key b for Bob: ");
    scanf("%lld", &b);
    y = power(G, b, P); // gets the generated key

    // Generating the secret key after the exchange of keys
    ka = power(y, a, P); // Secret key for Alice
    kb = power(x, b, P); // Secret key for Bob

    printf("Secret key for Alice is: %lld\n", ka);
    printf("Secret key for Bob is: %lld\n", kb);

    if (ka == kb)
    {
        printf("Identical keys are exchanged.");
    }

    return 0;
}
