/*11.WAP to generate subkeys for user innput key(bits) in DES.*/
#include <stdio.h>
#include <stdlib.h>

// Permutation choice 1 (PC-1) table
int PC1[56] = {
    57, 49, 41, 33, 25, 17, 9,
    1, 58, 50, 42, 34, 26, 18,
    10, 2, 59, 51, 43, 35, 27,
    19, 11, 3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
    14, 6, 61, 53, 45, 37, 29,
    21, 13, 5, 28, 20, 12, 4};

// Permutation choice 2 (PC-2) table
int PC2[48] = {
    14, 17, 11, 24, 1, 5,
    3, 28, 15, 6, 21, 10,
    23, 19, 12, 4, 26, 8,
    16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32};

// Left shifts for each round
int left_shifts[16] = {
    1, 1, 2, 2, 2, 2, 2, 2,
    1, 2, 2, 2, 2, 2, 2, 1};

// Function to perform left circular shift
unsigned long leftCircularShift(unsigned long n, int shifts, int totalBits)
{
    return ((n << shifts) & ((1 << totalBits) - 1)) | (n >> (totalBits - shifts));
}

// Function to generate subkeys
void generateSubkeys(unsigned long key)
{
    unsigned long permutedKey = 0;
    int i;

    // Perform PC-1 permutation
    for (i = 0; i < 56; i++)
    {
        permutedKey <<= 1;
        permutedKey |= (key >> (64 - PC1[i])) & 1;
    }

    // Split the key into two halves
    unsigned long C = (permutedKey >> 28) & 0x0FFFFFFF;
    unsigned long D = permutedKey & 0x0FFFFFFF;

    // Generate the 16 subkeys
    for (i = 0; i < 16; i++)
    {
        // Perform the left circular shift
        C = leftCircularShift(C, left_shifts[i], 28);
        D = leftCircularShift(D, left_shifts[i], 28);

        // Combine the halves
        unsigned long combined = (C << 28) | D;

        // Apply PC-2 permutation
        unsigned long subkey = 0;
        for (int j = 0; j < 48; j++)
        {
            subkey <<= 1;
            subkey |= (combined >> (56 - PC2[j])) & 1;
        }

        // Print the subkey
        printf("Subkey %2d: ", i + 1);
        for (int k = 47; k >= 0; k--)
        {
            printf("%lu", (subkey >> k) & 1);
        }
        printf("\n");
    }
}

int main()
{
    unsigned long key;
    printf("Enter a 64-bit key in hexadecimal (e.g., 0x133457799BBCDFF1): ");
    scanf("%lx", &key);

    generateSubkeys(key);

    return 0;
}
