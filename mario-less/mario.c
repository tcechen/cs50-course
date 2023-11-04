#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // user input height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // print out bricks
    for (int i = 1; i <= height; i++)
    {
        for (int j = height; j >= 0; j--)
        {
            if(j > i)
            {
                printf(" ");
            }
            else if (j == i)
            {
                printf("");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}