//
// Created by pyxisha on 2021/5/31.
//

#include <string.h>
#include <stdio.h>

int lengthOfLastWord(char * s){
    int n = strlen(s);
    int i = n - 1;

    int ret = 0;
    while (i >= 0 && s[i] == ' ') i--;
    while (i >= 0 && s[i] != ' ') {i--; ret++;};

    return ret;
}

int main(void)
{
    printf("%d\n", lengthOfLastWord(""));
    printf("%d\n", lengthOfLastWord(" "));
    printf("%d\n", lengthOfLastWord("hello word"));
}