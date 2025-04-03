#include <stdlib.h>
#include <stdio.h>  
#include <string.h> 
#include <locale.h>

void delete_str_array(char ***array)
{
    if (!array || !*array) return;

    for (int i = 0; (*array)[i] != NULL; i++) {
        free((*array)[i]);
        printf("Libéré: %p\n", (*array)[i]);
    }

    printf("Libération du tableau: %p\n", *array);
    free(*array);
    
    *array = NULL;
}

int main()
{
    setlocale(LC_ALL, "French_France.65001");
    system("chcp 65001 > nul");

    char **strings = malloc(4 * sizeof(char *));
    strings[0] = strdup("Bonjour");
    strings[1] = strdup("le");
    strings[2] = strdup("monde");
    strings[3] = NULL;

    printf("AVANT:\n");
    for (int i = 0; strings[i] != NULL; i++) {
        printf("[%d]: %s (adresse: %p)\n", i, strings[i], strings[i]);
    }

    printf("\nDÉBUT DU NETTOYAGE\n");
    delete_str_array(&strings);
    printf("FIN DU NETTOYAGE\n\n");

    printf("APRÈS:\n");
    if (strings == NULL) {
        printf("Le pointeur est bien NULL (nettoyage reussi)\n");
    } else {
        printf("ERREUR: Le pointeur n'est pas NULL!\n");
    }

    system("pause");
    return 0;
}