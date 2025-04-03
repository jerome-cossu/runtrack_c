# include <stdio.h>
void write_char(char c)
{
    write(1, &c, 1);
}

unsigned int ft_strlen(const char *s)
{
    unsigned int len = 0;
    while (s[len])
        len++;
    return len;
}

char *ft_strdup(const char *s)
{
    unsigned int len = ft_strlen(s) + 1;
    char *dup = malloc(len);
    if (!dup)
        return NULL;
    unsigned int i = 0;
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return dup;
}

char *ft_substr(char const *s, unsigned int start, unsigned int len)
{
    if (!s)
        return NULL;
    unsigned int s_len = ft_strlen(s);
    if (start >= s_len)
        return ft_strdup("");
    if (len > s_len - start)
        len = s_len - start;
    char *sub = malloc(len + 1);
    if (!sub)
        return NULL;
    unsigned int i = 0;
    while (i < len && s[start + i])
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return sub;
}

int ft_isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

char *ft_strtrim(char const *s)
{
    if (!s)
        return NULL;
    
    unsigned int start = 0;
    while (s[start] && ft_isspace(s[start]))
        start++;
    
    unsigned int end = ft_strlen(s);
    while (end > start && ft_isspace(s[end - 1]))
        end--;
    
    return ft_substr(s, start, end - start);
}

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void ft_swap(char **a, char **b)
{
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort_words(char **words, int count)
{
    int i = 0;
    int j;
    
    while (i < count - 1)
    {
        j = 0;
        while (j < count - i - 1)
        {
            if (ft_strcmp(words[j], words[j + 1]) > 0)
                ft_swap(&words[j], &words[j + 1]);
            j++;
        }
        i++;
    }
}

void print_words(char **words, int count)
{
    int i = 0;
    while (i < count)
    {
        unsigned int j = 0;
        while (words[i][j])
        {
            write_char(words[i][j]);
            j++;
        }
        if (i < count - 1)
            write_char(' ');
        i++;
    }
    write_char('\n');
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        write_char('\n');
        return 0;
    }
    
    char **words = malloc((argc - 1) * sizeof(char *));
    if (!words)
        return 1;
    
    int i = 1;
    int word_count = 0;
    while (i < argc)
    {
        words[word_count] = ft_strtrim(argv[i]);
        if (words[word_count] && *words[word_count])
            word_count++;
        else if (words[word_count])
            free(words[word_count]);
        i++;
    }
    
    sort_words(words, word_count);
    print_words(words, word_count);
    
    i = 0;
    while (i < word_count)
    {
        free(words[i]);
        i++;
    }
    free(words);
    
    return 0;
}