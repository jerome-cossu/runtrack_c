#include <stdlib.h>
#include <stdbool.h>

static bool is_space(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

static int count_words(const char *str)
{
    int count = 0;
    bool in_word = false;

    while (*str) {
        if (!is_space(*str)) {
            if (!in_word) {
                count++;
                in_word = true;
            }
        } else {
            in_word = false;
        }
        str++;
    }
    return count;
}

char **split(const char *str)
{
    if (!str) return NULL;
    
    int word_count = count_words(str);
    char **result = malloc((word_count + 1) * sizeof(char *));
    if (!result) return NULL;
    
    int word_index = 0;
    const char *word_start = str;
    bool in_word = false;
    
    while (*str) {
        if (!is_space(*str)) {
            if (!in_word) {
                word_start = str;
                in_word = true;
            }
        } else {
            if (in_word) {
                int word_len = str - word_start;
                result[word_index] = malloc(word_len + 1);
                if (!result[word_index]) {

                    for (int i = 0; i < word_index; i++) {
                        free(result[i]);
                    }
                    free(result);
                    return NULL;
                }
                for (int i = 0; i < word_len; i++) {
                    result[word_index][i] = word_start[i];
                }
                result[word_index][word_len] = '\0';
                word_index++;
                in_word = false;
            }
        }
        str++;
    }

    if (in_word) {
        int word_len = str - word_start;
        result[word_index] = malloc(word_len + 1);
        if (!result[word_index]) {
            for (int i = 0; i < word_index; i++) {
                free(result[i]);
            }
            free(result);
            return NULL;
        }
        for (int i = 0; i < word_len; i++) {
            result[word_index][i] = word_start[i];
        }
        result[word_index][word_len] = '\0';
        word_index++;
    }
    
    result[word_index] = NULL;
    return result;
}

#include <stdio.h>

int main() {
    char *str = "  Hello   world\tthis\nis a test  ";
    char **words = split(str);
    
    if (words) {
        for (int i = 0; words[i] != NULL; i++) {
            printf("Word %d: '%s'\n", i, words[i]);
        }
        
        for (int i = 0; words[i] != NULL; i++) {
            free(words[i]);
        }
        free(words);
    }
    
    return 0;
}