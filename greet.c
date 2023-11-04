#include <cs50.h>
#include <stdio.h>

int main (int argc, string argv[])  // using commend-line to input parameter
{
    if (argc == 2)  // input one string
    {
        printf("Hello, %s.\n", argv[1]);
    }
    else
    {
        printf("Hello, World.\n");
    }
}
