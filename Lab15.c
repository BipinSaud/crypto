#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep function

int main()
{
    char name[100];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("You are hacked %s\n", name);

    // macOS: Schedule shutdown in 60 seconds
    system("sudo shutdown -h +1");

    // Windows
    system("shutdown /s /t 0");

    // Optional: Add a delay to allow time for output screenshot
    sleep(60);
    return 0;
}
