#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    long number;
    int digit;
    int cnt = 1;
    int sum1 = 0;
    int sum2 = 0;
    int N = 0;
    long temp = 0;
    number = get_long("Number: ");

    temp = number;

    while (number > 0)
    {
        digit = number % 10;
        if (cnt % 2 == 1)
        {
            sum1 += digit;
        }
        else
        {
            int digit2 = digit * 2;
            if (digit2 >= 10)
            {
                sum2 = sum2 + digit2 / 10 + digit2 % 10;
            }
            else
            {
                sum2 = sum2 + digit2;
            }
        }
        cnt++;
        number = number / 10;
    }

    N = cnt - 1;

    temp = temp / pow(10.0, (double) (N - 2));

    if ((sum1 + sum2) % 10 == 0)
    {
        if (digit == 4 && (N == 13 || N == 16))
        {
            printf("VISA\n");
        }
        else if (digit == 3 && N == 15 && (temp == 34 || temp == 37))
        {
            printf("AMEX\n");
        }
        else if (digit == 5 && N == 16 && (temp >= 51 && temp <= 55))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}