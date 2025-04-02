int my_strlen(char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

#include <stdio.h>

int main()
{
    char *str = "Hello";
    printf("Length: %d\n", my_strlen(str));
    return 0;
}