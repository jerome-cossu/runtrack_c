#include <stdlib.h>

char **array_clone(char **array, int n)
{
    int len = 0;
    char **clone;
    int i, j;

    // 1. Calculer la taille du nouveau tableau
    while (len < n && array[len] != NULL)
        len++;

    // 2. Allouer le tableau clone (+1 pour NULL final)
    clone = malloc(sizeof(char *) * (len + 1));
    if (!clone)
        return NULL;

    // 3. Copier chaque chaîne
    i = 0;
    while (i < len)
    {
        // Calcul de la longueur de la chaîne
        int str_len = 0;
        while (array[i][str_len] != '\0')
            str_len++;

        // Allocation (+1 pour '\0')
        clone[i] = malloc(sizeof(char) * (str_len + 1));
        if (!clone[i])
            return NULL;  // Échec malloc (gestion simplifiée)

        // Copie caractère par caractère
        j = 0;
        while (array[i][j] != '\0')
        {
            clone[i][j] = array[i][j];
            j++;
        }
        clone[i][j] = '\0';  // Terminaison explicite
        i++;
    }

    // 4. Terminer le tableau par NULL
    clone[len] = NULL;

    return clone;
}
#include <stdio.h>

char    **array_clone(char **array, int n);

int main()
{
    char *original[] = {"Hello", "World", "Test", NULL}; 
    char **clone = array_clone(original, 5);
    for (int i = 0; clone[i] != NULL; i++)
        printf("%s\n", clone[i]);

    for (int i = 0; clone[i] != NULL; i++)
        free(clone[i]);
    free(clone);

    return (0);
}