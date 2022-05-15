from typing import *

class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        ret = []
        ret.append(words[0])

        i = 1
        while i < len(words):
            s = words[i]
            if sorted(s) != sorted(ret[-1]):
                ret.append(s)
            i += 1
        return  ret


solu = Solution()
print(solu.removeAnagrams(["abba","baba","bbaa","cd","cd"]))