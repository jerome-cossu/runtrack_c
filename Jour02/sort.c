#include <stdio.h>
void    sort(char **array)
{
    int     i;
    int     j;
    char    *temp;

    if (!array || !*array)
        return;  
    i = 0;
    while (array[i] != NULL)
    {
        j = 0;
        while (array[j + 1] != NULL)
        {
            int k = 0;
            while (array[j][k] == array[j + 1][k] && array[j][k] != '\0' && array[j + 1][k] != '\0')
                k++;

            if (array[j][k] > array[j + 1][k])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}
#include <stdio.h>

void    sort(char **array);

int main()
{
    char *words[] = {"banana", "apple", "cherry", "date", NULL};
    sort(words);

    for (int i = 0; words[i] != NULL; i++)
        printf("%s\n", words[i]);

    return 0;
}