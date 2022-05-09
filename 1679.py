from typing import *

class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        m = {}
        for n in nums:
            if n not in m:
                m[n] = 0
            m[n] += 1

        ret = 0
        for n in nums:
            if n in m and k - n in m and m[n] > 0 and m[k - n] > 0:
                m[n] -= 1
                m[k - n] -= 1
                if m[n] >= 0:
                    ret += 1

        return ret

solu = Solution()
print(solu.maxOperations([1,2,3,4], 5))
print(solu.maxOperations([3,1,3,4,3], 6))