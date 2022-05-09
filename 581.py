from typing import *

class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        s = sorted(nums)
        ret = len(nums)
        i = 0
        while i < len(nums) and s[i] == nums[i]:
            i += 1
            ret -= 1
        j = len(nums) - 1
        while j > i and s[j] == nums[j]:
            j -= 1
            ret -= 1
        return ret


solu = Solution()
print(solu.findUnsortedSubarray([2,6,4,8,10,9,15]))
print(solu.findUnsortedSubarray([1, 2, 3, 4]))