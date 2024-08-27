/*5.WAP to test if a number is primite root or not.*/
#include <stdio.h>
#include <math.h>

int is_primitive_root(int g, int p, int values[])
{
    for (int i = 0; i < p - 1; i++)
    {
        values[i] = (int)pow(g, i) % p;
    }

    // Check if all numbers from 1 to (p-1) can be found in the calculated values
    for (int i = 1; i < p; i++)
    {
        int found = 0;
        for (int j = 0; j < p - 1; j++)
        {
            if (values[j] == i)
            {
                found = 1;
                break; // Exit inner loop if found
            }
        }
        if (!found)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int p, g;
    int values[100];
    printf("Enter the prime number p:");
    scanf("%d", &p);
    printf("Enter the value of g:");
    scanf("%d", &g);
    int g_mod_p = g % p;
    if (is_primitive_root(g, p, values))
    {
        printf("\n%d is a primitive root of %d.\n", g, p);
        printf("Values of g^i mod p are:\n");
        for (int i = 0; i < p - 1; i++)
        {
            printf("%d^%d mod %d = %d\n", g, i, p, values[i]);
        }
        printf("Distinct values \n");
    }
    else
    {
        printf("%d is not a primitive root of %d.\n", g, p);
    }

    return 0;
}
