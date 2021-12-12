//
// Created by pyxisha on 2021/5/29.
//

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

int romanToInt(char * s) {
    int i = 0;
    int ret = 0;
    int map[128] = {0};
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;

    while (s[i]) {
        if (s[i + 1] != 0 && map[s[i + 1]] > map[s[i]]) {
            ret -= map[s[i]];
        } else {
            ret += map[s[i]];
        }
        s++;
    }

    return ret;
}

#include <stdio.h>

int main(void)
{
    printf("%d\n", romanToInt("LVIII"));
    printf("%d\n", romanToInt("MCMXCIV"));
}