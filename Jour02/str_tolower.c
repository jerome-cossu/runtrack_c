#include <stdlib.h>
#include <unistd.h>

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i]) i++;
    write(1, str, i);
    write(1, "\n", 1);
}

char *ft_str_tolower(char *str)
{
    if (!str) return NULL;
    
    int i = 0;
    while (str[i]) i++;
    
    char *result = malloc(i + 1);
    if (!result) return NULL;
    
    i = 0;
    while (str[i])
    {
        result[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : str[i];
        i++;
    }
    result[i] = '\0';
    return result;
}

int main(int argc, char **argv)
{
    if (argc < 2) return 0;
    
    for (int i = 1; i < argc; i++)
    {
        char *lower = ft_str_tolower(argv[i]);
        if (!lower) return 1;
        
        ft_putstr(lower);
        free(lower);
    }
    return 0;
}