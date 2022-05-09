from typing import *

class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        h1 = {}
        h2 = {}
        ret = 0

        for x in nums1:
            for y in nums2:
                if x + y not in h1:
                    h1[x + y] = 1
                else:
                    h1[x + y] += 1

        for x in nums3:
            for y in nums4:
                if x + y not in h2:
                    h2[x + y] = 1
                else:
                    h2[x + y] += 1

        for x in h1:
            for y in h2:
                if x + y == 0:
                    ret += h1[x] * h2[y]

        return ret

solu = Solution()
print(solu.fourSumCount([1, 2], [-2, -1], [-1, 2], [0, 2]))