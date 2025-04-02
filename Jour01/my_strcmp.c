int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    int diff = *(unsigned char *)s1 - *(unsigned char *)s2;
    return (diff > 0) ? 1 : ((diff < 0) ? -1 : 0);
}

#include <stdio.h>

int main() {
    printf("%d\n", my_strcmp("abc", "abc"));   // 0
    printf("%d\n", my_strcmp("abc", "abd"));   // -1 (car 'c' - 'd' = -1)
    printf("%d\n", my_strcmp("abd", "abc"));   // 1 (car 'd' - 'c' = 1)
    printf("%d\n", my_strcmp("ab", "abc"));    // -99 → devient -'c' (-99)
    printf("%d\n", my_strcmp("abc", "ab"));    // +'c' (99)
    return 0;
}