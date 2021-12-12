//
// Created by pyxisha on 2021/6/5.
//

#define SWAP(a, b) do { __typeof__(a) tmp = a; a = b; b = tmp;} while (0)

void sortColors(int* nums, int numsSize){
    int lo = 0, hi = numsSize - 1, mid =-1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            SWAP(nums[0], nums[i]);
            mid = 0;
            lo = 1;
        }
    }

    if (mid == -1) {
        while (lo < hi) {
            if (nums[lo] == 0) lo++;
            else if (nums[hi] == 2) hi--;
            else {
                SWAP(nums[lo], nums[hi]);
            }
        }
    } else {
        while (lo <= hi) {
            if (nums[lo] == 0) {
                SWAP(nums[mid], nums[lo]);
                lo++;
                mid++;
            } else if (nums[lo] == 1) {
                lo++;
            } else {
                SWAP(nums[lo], nums[hi]);
                hi--;
            }
        }
    }
}

int main(void) {
    int arr1[10] = {0, 2, 2, 0, 2};
    int arr2[10] = {1, 2, 0, 1, 0, 2};

    sortColors(arr1, 5);
    sortColors(arr2, 6);

    return 0;
}