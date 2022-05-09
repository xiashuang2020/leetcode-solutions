from typing import *

class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        numss = sorted(nums)
        i = len(nums) // 2
        if len(nums) % 2 == 0:
            i -= 1

        j = len(nums) - 1
        t = 0
        while t < len(nums):
            if t % 2 == 0:
                nums[t] = numss[i]
                i -= 1
            else:
                nums[t] = numss[j]
                j -= 1
            t += 1


solu = Solution()
test1 = [1, 2, 3, 4, 5, 6, 7]
solu.wiggleSort(test1)
print(test1)
test2 = [1, 2, 3, 4, 5, 6, 7, 8]
solu.wiggleSort(test2)
print(test2)
test3 = [1, 1, 2, 2, 3, 3]
solu.wiggleSort(test3)
print(test3)
test4 = [4, 5, 5, 6]
solu.wiggleSort(test4)
print(test4)