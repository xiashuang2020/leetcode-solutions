//
// Created by pyxisha on 2021/12/19.
//


#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char * addSpaces(char * s, int* spaces, int spacesSize){
    int len = strlen(s);
    char *ret;
    int i = 0;
    int j = 0;
    int k = 0;

    ret = calloc(len + spacesSize + 1, 1);


    while (j < spacesSize) {
        int space_idx = spaces[j];
        while (i < space_idx) {
            ret[k++] = s[i++];
        }
        ret[k++] = ' ';
        j++;
    }

    while (i < len) {
        ret[k++] = s[i++];
    }

    return ret;

}

int main(void)
{
    char* s1 = "LeetcodeHelpsMeLearn";
    int test1[3] = {8, 13, 15};
    printf(addSpaces(s1, test1, 3));
}