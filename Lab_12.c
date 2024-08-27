/*12.WAP to convert the plaintext in bits into state array.*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert plaintext to a state array of corresponding positions (0-25)
void plaintext_to_state_array(const char *plaintext, unsigned char state[4][4])
{
    for (int i = 0; i < 16; i++)
    {
        int row = i / 4;
        int col = i % 4;
        if (i < strlen(plaintext) && isalpha(plaintext[i]))
        {
            // Convert character to uppercase and find its position (0-25)
            state[row][col] = toupper(plaintext[i]) - 'A';
        }
        else
        {
            state[row][col] = 0; // Padding with 0 if the character is not a letter
        }
    }
}

// Function to convert plaintext characters to their binary representation and store in a 4x4 matrix
void plaintext_to_bits(const char *plaintext, unsigned char bits[16][8])
{
    for (int i = 0; i < 16; i++)
    {
        unsigned char ch = (i < strlen(plaintext) && isalpha(plaintext[i])) ? toupper(plaintext[i]) - 'A' : 0;
        for (int j = 0; j < 8; j++)
        {
            bits[i][j] = (ch >> (7 - j)) & 1;
        }
    }
}

// Function to print the state array in hexadecimal
void print_state_array_hex(unsigned char state[4][4])
{
    printf("State array in hex:\n");
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            printf("%02X ", state[row][col]);
        }
        printf("\n");
    }
}

// Function to print the bit representation of the plaintext in a 4x4 matrix
void print_bits_matrix(unsigned char bits[16][8])
{
    printf("Plaintext in bits (4x4 matrix):\n");
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d", bits[i][j]);
        }
        printf(" ");
        if ((i + 1) % 4 == 0)
        {
            printf("\n");
        }
    }
}

int main()
{
    char plaintext[256];

    printf("Enter the plaintext (up to 16 characters): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    unsigned char state[4][4] = {0}; // Initialize state array with zeros
    unsigned char bits[16][8] = {0}; // Initialize bits array with zeros

    plaintext_to_state_array(plaintext, state);
    plaintext_to_bits(plaintext, bits);

    print_bits_matrix(bits);
    print_state_array_hex(state);

    return 0;
}