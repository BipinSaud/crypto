/*13.WAP to encrypt and decrypt the message using RSA.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute GCD of two numbers
int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

// Function to perform modular exponentiation
// It returns (base^exp) % mod
long long mod_exp(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        { // If exp is odd, multiply base with result
            result = (result * base) % mod;
        }
        exp = exp >> 1;             // exp = exp / 2
        base = (base * base) % mod; // base = base^2 % mod
    }
    return result;
}

int main()
{
    int p, q, n, phi;
    int d = 2, e = 2;
    char message[100];
    long long c, m1;

    // Input prime numbers p and q
    printf("Enter 1st prime number: ");
    scanf("%d", &p);
    printf("Enter 2nd prime number: ");
    scanf("%d", &q);
    printf("Enter message: ");
    scanf("%s", message);

    // Calculate n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    printf("\nFormulas for key generation:");
    printf("\nn = p * q");
    printf("\nphi = (p - 1) * (q - 1)");
    printf("\nFind e such that GCD(e, phi) == 1");
    printf("\nFind d such that (d * e) %% phi == 1\n");

    printf("\nValues:");
    printf("\nValue of n is: %d", n);
    printf("\nValue of phi is: %d\n", phi);

    // Find e such that GCD(e, phi) == 1
    while (GCD(e, phi) != 1)
    {
        e++;
    }

    // Find d such that (d * e) % phi == 1
    while ((d * e) % phi != 1)
    {
        d++;
    }

    printf("\nValue of e = %d", e);
    printf("\nValue of d = %d\n\n", d);

    printf("\n\nEncryption\n");
    printf("Encryption formula: c = (m^e) %% n\n");
    // Encrypt the message
    printf("Encrypted characters:\n");
    for (int i = 0; i < strlen(message); i++)
    {
        int m = message[i];
        c = mod_exp(m, e, n);
        int encrypted_mod26 = c % 26;
        char encrypted_char = 'A' + encrypted_mod26;
        printf("Character '%c' (ASCII %d) encrypted to %lld (mod 26: %d, as char: '%c')\n",
               message[i], m, c, encrypted_mod26, encrypted_char);
    }

    printf("\n\nDecryption\n");
    printf("Decryption formula: m = (c^d) %% n\n");
    // Decrypt the message
    printf("Decrypted characters:\n");
    for (int i = 0; i < strlen(message); i++)
    {
        int m = message[i];
        c = mod_exp(m, e, n);
        m1 = mod_exp(c, d, n);
        printf("Encrypted value %lld decrypted to character '%c' (ASCII %lld)\n", c, (char)m1, m1);
    }

    return 0;
}
