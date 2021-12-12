//
// Created by pyxisha on 2021/5/29.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    int i;
    char *common = calloc(250, 1);

    strcpy(common, strs[0]);

    for (i = 1; i < strsSize; i++) {
        char *s = strs[i];
        int j = 0;
        while (s[j] != 0 && s[j] == common[j])
            j++;
        common[j] = 0;
    }

    return common;
}

int main(void)
{
    char *strs[3] = {"dog","racecar","car"};
    char *strs2[3] = {"flower","flow","flight"};

    printf("%s\n", longestCommonPrefix(strs, 3));
    printf("%s\n", longestCommonPrefix(strs2, 3));
}