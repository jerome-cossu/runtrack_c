#include <stdlib.h>
#include <stdbool.h>

bool is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

char *trim(const char *src) {
    if (src == NULL) {
        return NULL;
    }

    const char *start = src;
    while (*start && is_whitespace(*start)) {
        start++;
    }

    const char *end = src;
    while (*end) {
        end++;
    }
    end--;
    while (end >= start && is_whitespace(*end)) {
        end--;
    }
    size_t len = (end >= start) ? (end - start + 1) : 0;

    char *dest = malloc(len + 1); 
    if (dest == NULL) {
        return NULL;
    }

    char *ptr = dest;
    while (start <= end) {
        *ptr++ = *start++;
    }
    *ptr = '\0';

    return dest;
}
#include <stdio.h>

int main() {
    char *str = "  \tHello World\n ";
    char *trimmed = trim(str);
    
    printf("Original: \"%s\"\n", str);
    printf("Trimmed: \"%s\"\n", trimmed);
    
    free(trimmed); // Ne pas oublier de libérer la mémoire
    return 0;
}