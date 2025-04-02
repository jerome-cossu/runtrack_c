char *my_strcpy(char *dest, const char *src) {
    if (!dest || !src) return dest;
    
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

char *my_strcpy(char *dest, const char *src);

int main() {
    char src[] = "Bonjour comment vas-tu?";
    char dest[24];

    my_strcpy(dest, src);
    printf("Fin de la copie : %s\n", dest);
    return 0;
}