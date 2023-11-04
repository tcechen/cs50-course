#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void turn_binary(string s);

int main(void)
{
    // TODO
    string s = get_string("Message: ");

    turn_binary(s);
}

void turn_binary(string s)
{
    int b; // number of bit
    int num;

    for (int i = 0; i < strlen(s); i++)
    {
        b = (int) pow(2.0, BITS_IN_BYTE - 1);
        num = (int) s[i];
        while (b > 0)
        {
            if (num >= b)
            {
                print_bulb(1); // print light bulb emoji
                num = num - b;
                b = b / 2; // update b value divided by 2
            }
            else
            {
                print_bulb(0); // print dark bulb emoji
                b = b / 2;     // update b value divided by 2
            }
        }
        printf("\n"); // change to next char
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
