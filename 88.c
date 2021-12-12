//
// Created by pyxisha on 2021/6/6.
//



void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1 = n, p2 = 0, k = 0;

    for (int i = m - 1; i >= 0; i--) {
        nums1[n + i] = nums1[i];
    }

    while (p1 < m + n || p2 < n) {
        if (p1 >= m + n)
            nums1[k++] = nums2[p2++];
        else if (p2 >= n)
            nums1[k++] = nums1[p1++];
        else {
            if (nums1[p1] <= nums2[p2]) {
                nums1[k++] = nums1[p1++];
            } else {
                nums1[k++] = nums2[p2++];
            }
        }

    }
}