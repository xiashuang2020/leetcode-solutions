//
// Created by xiash on 2022/4/26.
//

void moveZeroes(int *nums, int numSize)
{
    int i = 0, j = 0;

    while (i < numSize && nums[i] != 0)
        i++;
    j = i + 1;
    while (j < numSize) {
        while (j < numSize && nums[j] == 0)
            j++;
        if (j < numSize) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;
        }
    }
}

int main(void)
{
    int test[5] = {0, 1, 0, 3, 12};
    moveZeros(test, 5);

    return 0;
}