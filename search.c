#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {50, 1, 100, 500, 30, 60, 120};

    int n = get_int("Number: ");
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found.\n");
            return 0;
        }
    }
    printf("Not found.\n");
    return 1;
}