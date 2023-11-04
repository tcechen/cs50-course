#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%p\n",s);
    printf("%p\n",&s[0]); // same as s
    printf("%s\n",s);

    printf("%c\n",*s);
    printf("%c\n",*(s+1));
    printf("%c\n",*(s+2));

    printf("%s\n", s);
    printf("%s\n", s+1);
    printf("%s\n", s+2);
}