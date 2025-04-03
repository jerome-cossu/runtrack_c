void divide(int *n)
{
    *n = *n / 2;
}
#include <stdio.h>

void divide(int *n);

int main()
{
    int x = 10;
    printf("Avant : %d\n", x); 
    divide(&x);                
    printf("Apres : %d\n", x); 
}