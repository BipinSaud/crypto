/*1. WAP to encrypt and decrypt the user input message and key using caeser cipher. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[100], ch;
    int key, i;
    printf("Encryption and decryption for caeser cipher:\n");

    printf("Enter the input message: \t");
    gets(input);

    printf("Enter the key(0-25): \t");
    scanf("%d", &key);

    // Encryption
    for (i = 0; input[i] != '\0'; ++i)
    {
        ch = input[i];
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;
            if (ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            input[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;
            if (ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            input[i] = ch;
        }
    }
    printf("Encrypted message: %s\n", input);

    // Decryption
    for (i = 0; input[i] != '\0'; ++i)
    {
        ch = input[i];
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - key;
            if (ch < 'a')
            {
                ch = ch + 'z' - 'a' + 1;
            }
            input[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch - key;
            if (ch < 'A')
            {
                ch = ch + 'Z' - 'A' + 1;
            }
            input[i] = ch;
        }
    }
    printf("Decrypted message: %s\n", input);

    return 0;
}
