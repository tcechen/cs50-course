#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void ciphertext(string key, string text);

int main(int argc, string argv[])
{

    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isalpha(argv[1][i]) == false)
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
            for (int j = i + 1; j < strlen(argv[1]); j++)
            {
                if (toupper(argv[1][i]) == toupper(argv[1][j]))
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
            }
        }
    }

    string text = get_string("plaintext: ");

    ciphertext(argv[1], text);
}

void ciphertext(string key, string text)
{
    int index = 0;

    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) == false)
        {
            printf("%c", text[i]);
        }
        else if (isupper(text[i])) // text is uppercase
        {
            index = (int) text[i] - 65;
            if (isupper(key[index])) // key is uppercase
            {
                printf("%c", key[index]);
            }
            else // key is lowercase
            {
                printf("%c", key[index] - 32); // turn ascii to uppercase
            }
        }
        else // text is lowercase
        {
            index = (int) text[i] - 97;
            if (islower(key[index])) // key is lowercase
            {
                printf("%c", key[index]);
            }
            else // key is uppercase
            {
                printf("%c", key[index] + 32); // turn ascii to lowercase
            }
        }
    }
    printf("\n");
}