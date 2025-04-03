#include <stdio.h>
#include <stdlib.h>  

void func_to_array(char **array, void (*f)(char *))
{
    if (!array || !f) return;
    
    for (int i = 0; array[i] != NULL; i++) {
        f(array[i]);
    }
}

void strtoupper(char *s)
{
    for (int i = 0; s[i]; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
    }
}

void my_putstr(char *s)
{
    printf("%s\n", s);
    fflush(stdout);  
}

int main()
{

    char *words[] = {strdup("Hello"), strdup("World"), strdup("Test"), NULL};
    
    printf("Avant majuscules:\n");
    func_to_array(words, my_putstr);

    printf("\nApres majuscules:\n");
    func_to_array(words, strtoupper);
    func_to_array(words, my_putstr);

    for (int i = 0; words[i] != NULL; i++) {
        free(words[i]);
    }

    system("pause");  
    return 0;
}