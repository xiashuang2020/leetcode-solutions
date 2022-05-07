from typing import *

class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        nums.sort()
        i = 1
        j = len(nums) - 1 if len(nums) % 2 == 1 else len(nums) - 2
        while i < j:
            tmp = nums[i]
            nums[i] = nums[j]
            nums[j] = tmp
            i += 2
            j -= 2

solu = Solution()
test1 = [1,2,3,4,5,6,7]
solu.wiggleSort(test1)
print(test1)
test2 = [1,2,3,4,5,6,7,8]
solu.wiggleSort(test2)
print(test2)
