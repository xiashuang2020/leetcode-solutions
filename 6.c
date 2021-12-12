//
// Created by pyxisha on 2021/4/14.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 通项计算，最后一块的临界条件 */

char * convert(char *s, int numRows){
    char *ret = NULL;
    int l, i, k, idx, raw, j;
    int chunk_number, chunk_num, chunk_idx, last_chunk_number;
    int raw_num[1000] = {0};

    if (!s || numRows == 1)
        return s;

    ret = calloc(1000, 1);
    l = (int)strlen(s);
    chunk_number = numRows * 2 - 2;
    chunk_num = (l + chunk_number - 1) / chunk_number;
    last_chunk_number = l - (chunk_num - 1) * chunk_number;

    for (k = 0; k < last_chunk_number; k++) {
        raw = k < numRows ? k : numRows - 1 - (k - numRows + 1);
        raw_num[raw] += 1;
    }

    for (i = 0; i < numRows - 1; i++) {
        raw_num[i] += i == 0 ? (chunk_num - 1) : (chunk_num - 1) * 2;
    }

    for (i = 0; i < l; i++) {
        k = i % chunk_number;
        chunk_idx = i / chunk_number;
        raw = k < numRows ? k : numRows - 1 - (k - numRows + 1);
        idx = 0;
        for (j = 0; j < raw; j++)
            idx += raw_num[j];
        idx += k == 0 || k == numRows - 1 ? chunk_idx : chunk_idx * 2;
        if (k >= numRows) idx += 1;
        ret[idx] = s[i];
    }

    return ret;
}

int main(void)
{
    printf("foooo %s\n", convert("abcdefghijklmn", 1));
    printf("foooo %s\n", convert("abcdefghijklmn", 2));
    printf("foooo %s\n", convert("abcdefghijklmn", 3));
    printf("foooo %s\n", convert("PAYPALISHIRING", 4));
}