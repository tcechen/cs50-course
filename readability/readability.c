#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int calcalution(string s);
int cal_coleman_index(int letters, int words, int sentences);
void print_grade(int index);

int main(void)
{

    int index = 0;

    string s = get_string("Text: ");

    index = calcalution(s);
    // print out grade value
    print_grade(index);
}

int calcalution(string s)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;
    int index;

    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            letters++;
        }
        else if (isblank(s[i]))
        {
            words++;
        }
        else if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            sentences++;
        }
    }
    words = words + 1;
    index = cal_coleman_index(letters, words, sentences);
    return index;
}

int cal_coleman_index(int letters, int words, int sentences)
{
    int index;
    // calculate Coleman-Liau index
    float L = 100.0 * letters / words;
    float S = 100.0 * sentences / words;
    index = (int) round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}

void print_grade(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}