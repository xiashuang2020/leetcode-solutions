//
// Created by pyxisha on 2021/4/11.
//

/* 疑惑运算符的作用 a ^b ^ b = a*/

int singleNumber(int A[], int n) {
    int result = 0;
    for (int i = 0; i<n; i++)
    {
        result ^=A[i];
    }
    return result;
}