#include <stdio.h>
unsigned int ft_strlen(const char *s)
{
    unsigned int len = 0;
    while (s[len])
        len++;
    return len;
}
char *ft_strdup(const char *s)
{
    unsigned int len = ft_strlen(s) + 1;
    char *dup = malloc(len);
    if (!dup)
        return NULL;
    unsigned int i = 0;
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return dup;
}
char ft_tolower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}
char *ft_strlower(const char *s)
{
    char *lower = ft_strdup(s);
    if (!lower)
        return NULL;
    unsigned int i = 0;
    while (lower[i])
    {
        lower[i] = ft_tolower(lower[i]);
        i++;
    }
    return lower;
}
void print_strings(char **strings, int count)
{
    unsigned int i = 0;
    while (i < count)
    {
        unsigned int j = 0;
        while (strings[i][j])
        {
            write(1, &strings[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}
int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;
    
    char **lower_strings = malloc((argc - 1) * sizeof(char *));
    if (!lower_strings)
        return 1;
    
    unsigned int count = 0;
    unsigned int i = 1;
    while (i < argc)
    {
        lower_strings[count] = ft_strlower(argv[i]);
        if (lower_strings[count])
            count++;
        i++;
    }
    
    print_strings(lower_strings, count);
    
    i = 0;
    while (i < count)
    {
        free(lower_strings[i]);
        i++;
    }
    free(lower_strings);
    
    return 0;
}