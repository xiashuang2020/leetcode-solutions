//
// Created by pyxisha on 2021/4/10.
//

/* 双指针，很简单 */

int removeDuplicates(int* nums, int numsSize){
    int i = 1, j = 1, prev;

    if (numsSize == 0)
        return 0;

    prev = nums[0];
    while (j < numsSize) {
        if (nums[j] > prev) {
            prev = nums[j];
            if (j > i) {
                nums[i] = nums[j];
            }
            i++;
            j++;
        } else {
            j++;
        }
    }

    return i;
}

int main(void) {
    int nums[10] = {0,0,1,1,1,2,2,3,3,4};
    int nums2[3] = {1,2,2};
    int ret = removeDuplicates(nums2, 3);

    return 0;
}