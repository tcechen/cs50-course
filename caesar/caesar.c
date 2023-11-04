#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    int key;
    int p;
    string c = argv[1];

    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; i < strlen(c); i++)
    {
        if (isdigit(c[i]) == false)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    key = atoi(c);

    string s = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]) == false) // is not alphabet
        {
            p = s[i];
        }
        else if (isupper(s[i])) // uppercase start with ASCII 65
        {
            p = ((s[i] - 65 + key) % 26) + 65;
        }
        else // lowercase start with ASCII 97
        {
            p = ((s[i] - 97 + key) % 26) + 97;
        }
        printf("%c", p);
    }
    printf("\n");
}
