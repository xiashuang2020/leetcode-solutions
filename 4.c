//
// Created by pyxisha on 2021/3/20.
//

/* 重点，边界条件 */

#define min(a, b) ((a) > (b) ? (b) : (a))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int l1 = nums1Size;
    int l2 = nums2Size;
    int left_max, right_min;
    int n = l1 + l2;
    int n1 = l1 / 2;
    int n2;
    int grow;
    int step_max;

    if (n == 1)
    {
        if (nums1Size)
            return nums1[0];
        else
            return nums2[0];
    }

    do {
        n2 = n / 2 - n1;

        if (n1 == 0) {
            left_max = nums2[n2 - 1];
            grow = 1;
        }
        else if (n2 == 0) {
            left_max = nums1[n1 - 1];
            grow = 0;
        }
        else {
            if (nums1[n1 - 1] > nums2[n2 - 1]) {
                left_max = nums1[n1 - 1];
                grow = 0;
            } else {
                left_max = nums2[n2 - 1];
                grow = 1;
            }
        }

        if (n1 == nums1Size)
            right_min = nums2[n2];
        else if (n2 == nums2Size)
            right_min = nums1[n1];
        else
            right_min = min(nums1[n1], nums2[n2]);

        if (left_max <= right_min)
            break;
        else {
            if (grow) {
                step_max = min(n2, nums1Size - n1);
                n1 = step_max > 1 ? n1 + step_max / 2 : n1 + 1;
            }
            else {
                step_max = min(l2 - n2, n1);
                n1 = step_max > 1 > n1 ? n1 - step_max / 2 : n1 - 1;
            }
        }
    } while(0 <= n1 && n1 <= nums1Size);

    if (n % 2 == 0)
        return ((double)left_max + right_min) / 2;
    else
        return (double)right_min;
}