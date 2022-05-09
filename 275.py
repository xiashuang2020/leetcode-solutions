class Solution:
    def hIndex(self, citations: List[int]) -> int:
        for i, citation in enumerate(citations):
            h = len(citations) - i
            if citation >= h:
                return h
        return 0