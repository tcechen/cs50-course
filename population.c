#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_num;
    int end_num;
    int year = 0;

    // input start number must not less than 9
    do
    {
        start_num = get_int("Start size: ");
    }
    while (start_num < 9);

    // input end number must not less then start_num
    do
    {
        end_num = get_int("End size: ");
    }
    while (end_num < start_num);

    // calculate year needed to reach end number
    while (start_num < end_num)
    {
        start_num = start_num + start_num / 3 - start_num / 4; // update startnum value
        year++;
    }

    printf("Years: %i\n", year);
}