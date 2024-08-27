/*4.WAP to encrypt and decrypt the message usingRailframe Cipher*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using Rail Fence cipher
char *encryptRailFence(char *message, int key)
{
    int len = strlen(message);
    char *encrypted = (char *)malloc((len + 1) * sizeof(char));
    int rail = 0, dir = 0;

    // Initialize the rail fence matrix
    char railMatrix[key][len];
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < len; j++)
        {
            railMatrix[i][j] = '\0';
        }
    }

    // Fill the rail fence matrix with the message
    for (int i = 0; i < len; i++)
    {
        railMatrix[rail][i] = message[i];

        if (rail == 0)
        {
            dir = 0;
        }
        else if (rail == key - 1)
        {
            dir = 1;
        }

        if (dir == 0)
        {
            rail++;
        }
        else
        {
            rail--;
        }
    }

    // Read the encrypted message from the rail fence matrix
    int k = 0;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (railMatrix[i][j] != '\0')
            {
                encrypted[k++] = railMatrix[i][j];
            }
        }
    }
    encrypted[k] = '\0';

    return encrypted;
}

// Function to decrypt the message using Rail Fence cipher
char *decryptRailFence(char *encrypted, int key)
{
    int len = strlen(encrypted);
    char *decrypted = (char *)malloc((len + 1) * sizeof(char));
    int rail = 0, dir = 0;

    // Initialize the rail fence matrix
    char railMatrix[key][len];
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < len; j++)
        {
            railMatrix[i][j] = '\0';
        }
    }

    // Fill the rail fence matrix with markers indicating the rail positions
    for (int i = 0; i < len; i++)
    {
        railMatrix[rail][i] = '*';

        if (rail == 0)
        {
            dir = 0;
        }
        else if (rail == key - 1)
        {
            dir = 1;
        }

        if (dir == 0)
        {
            rail++;
        }
        else
        {
            rail--;
        }
    }

    // Replace markers with characters from the encrypted message
    int index = 0;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (railMatrix[i][j] == '*' && index < len)
            {
                railMatrix[i][j] = encrypted[index++];
            }
        }
    }

    // Read the decrypted message from the rail fence matrix
    int k = 0;
    rail = 0, dir = 0;
    for (int i = 0; i < len; i++)
    {
        decrypted[k++] = railMatrix[rail][i];

        if (rail == 0)
        {
            dir = 0;
        }
        else if (rail == key - 1)
        {
            dir = 1;
        }

        if (dir == 0)
        {
            rail++;
        }
        else
        {
            rail--;
        }
    }
    decrypted[k] = '\0';

    return decrypted;
}

int main()
{
    char message[100], *encrypted, *decrypted;
    int key;

    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline character

    printf("Enter the key: ");
    scanf("%d", &key);

    encrypted = encryptRailFence(message, key);
    printf("Encrypted message: %s\n", encrypted);

    decrypted = decryptRailFence(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);

    free(encrypted);
    free(decrypted);

    return 0;
}
