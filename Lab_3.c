/*3.WAP to encrypt and decrypt the message using Vernam Cipher*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a key matching the length of the plaintext
char *generate_key(int plaintext_length)
{
    char *key = (char *)malloc((plaintext_length + 1) * sizeof(char));

    // Seed the random number generator
    srand(time(NULL));

    for (int i = 0; i < plaintext_length; i++)
    {
        key[i] = 'A' + rand() % 26; // Generate a random uppercase letter
    }
    key[plaintext_length] = '\0';

    return key;
}

// Function to perform XOR encryption
char *encrypt(const char *plaintext, const char *key)
{
    int plaintext_length = strlen(plaintext);
    char *ciphertext = (char *)malloc((plaintext_length + 1) * sizeof(char));

    for (int i = 0; i < plaintext_length; i++)
    {
        ciphertext[i] = plaintext[i] ^ key[i]; // XOR operation
    }
    ciphertext[plaintext_length] = '\0';

    return ciphertext;
}

// Function to perform XOR decryption
char *decrypt(const char *ciphertext, const char *key)
{
    int ciphertext_length = strlen(ciphertext);
    char *decrypted_text = (char *)malloc((ciphertext_length + 1) * sizeof(char));

    for (int i = 0; i < ciphertext_length; i++)
    {
        decrypted_text[i] = ciphertext[i] ^ key[i]; // XOR operation
    }
    decrypted_text[ciphertext_length] = '\0';

    return decrypted_text;
}

int main()
{
    char plaintext[100];
    char key[100];

    // Get the plaintext from the user
    printf("Please enter your message: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

    int plaintext_length = strlen(plaintext);

    // Get the key from the user
    printf("Please provide the key (must match message length): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove newline character

    // Encrypt the message
    char *ciphertext = encrypt(plaintext, key);
    printf("Encrypted Message (Hexadecimal): ");
    for (int i = 0; i < plaintext_length; i++)
    {
        printf("%02X", (unsigned char)ciphertext[i]);
    }
    printf("\n");

    // Decrypt the message
    char *decrypted_text = decrypt(ciphertext, key);
    printf("Decrypted Message: %s\n", decrypted_text);

    // Free dynamically allocated memory
    free(ciphertext);
    free(decrypted_text);

    return 0;
}
