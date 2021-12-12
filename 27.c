//
// Created by pyxisha on 2021/5/28.
//

int removeElement(int* nums, int numsSize, int val){
    int i = 0, j = 0;

    while (i < numsSize) {
        if (nums[i] != val)
            nums[j++] = nums[i];
        i++;
    }

    return j;
}