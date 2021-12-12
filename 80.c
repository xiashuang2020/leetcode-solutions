//
// Created by pyxisha on 2021/6/16.
//

int removeDuplicates(int* nums, int numsSize) {
    int i = 1; int j = 1;
    int two = 0;

    while (i < numsSize) {
        if (nums[i] == nums[i - 1]) {
            if (two) {
                i++;
            }
            else {
                nums[j++] = nums[i++];
                two = 1;
            }
        } else {
            two = 0;
            nums[j++] = nums[i++];
        }
    }

    return j;
}