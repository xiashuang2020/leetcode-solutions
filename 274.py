from typing import *

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        for i, citation in enumerate(citations):
            h = len(citations) - i
            if citation >= h:
                return h
        return 0

class Solution2:
    def hIndex(self, citations: List[int]) -> int:
        bucket = [0 for x in citations]
        bucket.append(0)
        for citation in citations:
            if citation < len(citations):
                bucket[citation] += 1
            else:
                bucket[len(citations)] += 1

        s = 0
        h = len(citations)
        while h > 0:
            s += bucket[h]
            if s >= h:
                return h
            h -= 1
        return 0


solu = Solution2()
''' print(solu.hIndex([3,0,6,1,5]))
print(solu.hIndex([1,3,1]))
print(solu.hIndex([0,0,0])) '''
print(solu.hIndex([1]))