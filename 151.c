//
// Created by pyxisha on 2021/5/2.
//

/* 先reverse整体，再reverse每个词 */

#include <stdio.h>
#include <string.h>

static void reverse(char *s, int l)
{
    char t;
    int i;

    for (i = 0; i < l / 2; i++)
    {
        t = s[i];
        s[i] = s[l - i - 1];
        s[l - i - 1] = t;
    }
}

char * reverseWords(char *s) {
    int i = 0;
    int j = 0;
    int k;
    unsigned long l;
    int world_len = 0;

    if (s == NULL)
        return s;

    l = strlen(s);

    k = l - 1;
    while (s[k] == ' ')
    {
        k--;
        l--;
    }

    while (j < l) {
        while (s[j] == ' ' && (j == 0 || s[j - 1] == ' '))
            j++;
        s[i] = s[j];
        i++;
        j++;
    }

    s[i] = 0;
    reverse(s, i);
    j = 0;
    while (j < i) {
        world_len = 0;
        while(j < i && s[j] != ' ') {
            j++;
            world_len++;
        }
        reverse(s + j - world_len, world_len);
        j++;
    }
    s[i] = 0;
    return s;
}

int main(void)
{
    char s[20] = "the sky is blue";
    char s1[20] = "a good   example";
    char s2[30] = "  Bob    Loves  Alice   ";
    char s3[20] = "  hello world  ";
    char s4[40] = "Alice does not even like bob";
    char s5[20] = "  abcde  ";

    printf("%s\n", reverseWords(s));
    printf("%s\n", reverseWords(s1));
    printf("%s\n", reverseWords(s2));
    printf("%s\n", reverseWords(s3));
    printf("%s\n", reverseWords(s4));
    printf("%s\n", reverseWords(s5));
}
