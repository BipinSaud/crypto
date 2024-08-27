/*14.WAP to encrypt and decrypt the message using Elgamel.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to compute gcd
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Extended Euclidean Algorithm to find d
int extended_gcd(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extended_gcd(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int mod_inverse(int a, int m)
{
    int x, y;
    int g = extended_gcd(a, m, &x, &y);
    if (g != 1)
    {
        printf("Inverse doesn't exist");
        exit(1);
    }
    return (x % m + m) % m;
}

int mod_exp(int base, int exp, int mod)
{
    int result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main()
{
    int q, alpha, Xa, Ya, c1, r, K1, K2, K_inverse;
    char message[256];

    printf("Enter a prime number q: ");
    scanf("%d", &q);
    printf("Enter alpha such that alpha is primitive root of q: ");
    scanf("%d", &alpha);

    printf("Key generation by Alice: \n");
    printf("Enter a private key(Xa) such that Xa < q: ");
    scanf("%d", &Xa);
    Ya = mod_exp(alpha, Xa, q);
    printf("Public key = {%d, %d, %d}\n", q, alpha, Ya);

    printf("Encryption by Bob with Alice's Public Key:\n");
    printf("Enter a message (uppercase letters only): ");
    scanf("%s", message);

    int length = strlen(message);
    int m[length], c2[length];

    printf("Message\tNumber\n");
    for (int i = 0; i < length; i++)
    {
        m[i] = message[i] - 'A';
        printf("%c\t%d\n", message[i], m[i]);
    }

    printf("Select a random integer r (r < q): ");
    scanf("%d", &r);

    K1 = mod_exp(Ya, r, q);
    printf("K1 = %d\n", K1);

    c1 = mod_exp(alpha, r, q);
    printf("c1 = %d\n", c1);
    printf("Message(0-25)\tNumber\n");
    for (int i = 0; i < length; i++)
    {
        c2[i] = (K1 * m[i]) % q;
        printf("%d\t\t%d\n", m[i], c2[i]);
    }

    printf("CipherText: (c1, c2)\n");
    printf("c1 = %d, c2 = ", c1);
    for (int i = 0; i < length; i++)
    {
        printf("%d ", c2[i]);
    }
    printf("\n");

    printf("Decryption by Alice with Alice's Private key: \n");
    K2 = mod_exp(c1, Xa, q);
    printf("K2 = %d\n", K2);

    K_inverse = mod_inverse(K2, q);
    printf("K_inverse = %d\n", K_inverse);

    printf("Decrypted message: ");
    for (int i = 0; i < length; i++)
    {
        int M = (c2[i] * K_inverse) % q;
        printf("%c", M + 'A');
    }
    printf("\n");

    return 0;
}