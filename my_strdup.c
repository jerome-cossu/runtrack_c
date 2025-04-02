#include <stdlib.h>

char *my_strdup(const char *src)
{
    if (src == NULL)
        return NULL;

    int len = 0;
    while (src[len] != '\0')
        len++;
    char *dest = malloc((len + 1) * sizeof(char));
    if (dest == NULL)
        return NULL; 
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *original = "Hello World";
    char *copy = my_strdup(original);
    
    if (copy != NULL)
    {
        printf("Original: %s\n", original);
        printf("Copy:     %s\n", copy);
        free(copy); 
    }
    else
    {
        printf("Memory allocation failed!\n");
    }
    
    return 0;
}