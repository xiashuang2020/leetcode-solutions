from typing import *

class Solution:
    def maxConsecutive(self, bottom: int, top: int, special: List[int]) -> int:
        special.append(bottom)
        special.append(top)

        special.sort()

        ret = special[1] - special[0]
        hi = 2
        while hi < len(special) - 1:
            if special[hi] - special[hi - 1] - 1 > ret:
                ret = special[hi] - special[hi - 1] - 1
            hi += 1

        if special[-1] - special[-2] > ret:
            ret = special[-1] - special[-2]
        return ret


solu = Solution()
print(solu.maxConsecutive(2, 9, [4, 6]))
print(solu.maxConsecutive(6, 8, [7, 6, 8]))

