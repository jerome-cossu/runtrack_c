void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
#include <stdio.h>

void swap(int *a, int *b);
int main()
{
    int x = 5;
    int y = 10;
    printf("Avant : x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("Apres : x = %d, y = %d\n", x, y);
    return 0;
}