from typing import *

class Solution:
    def countDistinct(self, nums: List[int], k: int, p: int) -> int:
        dp = [[]]
        dict = set()
        ret = 0
        for n in nums:
            if str(n)not in dict:
                dict.add(str(n))
                ret += 1
            if n % p == 0:
                dp[0].append(1)
            else:
                dp[0].append(0)

        i = 1
        whole_s = ','.join([str(x) for x in nums])
        while i < len(nums):
            j = 0
            dict.clear()
            dp.append([])
            start = 0
            end = 0
            for foo in range(i):
                end += len(str(nums[foo]))
            end += i - 1
            while i + j < len(nums):
                dp[i].append(dp[i - 1][j] + dp[0][i + j])
                end += len(str(nums[i + j])) + 1
                t = whole_s[start:end]
                if dp[i][j] <= k:
                    if t not in dict:
                        ret += 1
                        dict.add(t)
                j += 1
                start += len(str(nums[j - 1])) + 1
            i += 1

        return ret


solu = Solution()
print(solu.countDistinct([2,3,3,2,2], 2, 2))
print(solu.countDistinct([1,2,3,4], 4, 1))
print(solu.countDistinct([18,9,7,9,17,15,20], 6, 10))



