from typing import *

class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        h = {}
        ret = -1
        for i, card in enumerate(cards):
            if card not in h:
                h[card] = []
            h[card].append(i)
            if len(h[card]) >= 2 and (ret == -1 or h[card][-1] - h[card][-2] + 1 < ret):
                ret = h[card][-1] - h[card][-2] + 1
        return ret

solu = Solution()
print(solu.minimumCardPickup([3,4,2,3,4,7]))
print(solu.minimumCardPickup([1,2,3,4,5]))