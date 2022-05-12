from typing import *

class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ret = []

        def dfs(pre: List[int], psum: int):
            curr = 0 if len(pre) == 0 else pre[-1]
            for i in range(curr + 1, 10):
                if len(pre) == k - 1:
                    if psum + i == n:
                        a = pre.copy()
                        a.append(i)
                        ret.append(a)
                else:
                    if psum + i < n:
                        a = pre.copy()
                        a.append(i)
                        dfs(a, psum + i)

        dfs([], 0)
        return ret


solu = Solution()
print(solu.combinationSum3(3, 7))
print(solu.combinationSum3(3, 9))
print(solu.combinationSum3(4, 1))