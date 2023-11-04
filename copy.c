#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");
    string t = s; // copy the address of s

    t[0] = toupper(t[0]); // also change s value, because the address is same
    printf("%s\n",s);
    printf("%s\n",t);

    string s1 = get_string("s: ");
    string t1 = s1; // copy the address of s
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }
    printf("%s\n",s);
    printf("%s\n",t);

}