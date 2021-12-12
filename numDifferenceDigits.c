//
// Created by pyxisha on 2021/4/4.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int numDifferentIntegers(char * word) {
    int digits[1000] = {0};
    int len[1000] = {0};
    int start = 0;
    int num = 0;
    int i = 0, j = 0;

    while (word[i] != 0) {
        if ('0' <= word[i] && word[i] <= '9') {
            if (!start) {
                start = 1;
                digits[num] = i;
            } else if (i == digits[num] + 1 && word[digits[num]] == '0') {
                digits[num] += 1;
            }
        } else if (start) {
            start = 0;
            len[num] = i - digits[num];
            for (j = 0; j < num; j++) {
                if (len[num] == len[j] && strncmp(word + digits[num], word + digits[j], i - digits[num]) == 0)
                {
                    goto next_turn;
                }
            }
            num++;
        }

        next_turn:
        i++;
    }

    if (start) {
        start = 0;
        len[num] = i - digits[num];
        for (j = 0; j < num; j++) {
            if (len[num] == len[j] && strncmp(word + digits[num], word + digits[j], i - digits[num]) == 0)
            {
                return num;
            }
        }
        num++;
    }

    return num;
}

int main() {
    printf("%d\n", numDifferentIntegers("a123bc34d8ef34"));
}
