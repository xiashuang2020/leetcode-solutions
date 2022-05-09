from typing import *

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        q = []
        ret = []
        m = {'2': "abc", '3': "def", '4': "ghi", '5': "jkl", '6': "mno", '7': "pqrs", '8': "tuv", '9': "wxyz"}

        if len(digits) == 0:
            return ret
        q.append("")

        while len(q) != 0:
            s = q.pop(0)
            l = len(s)
            for x in m[digits[l]]:
                if l == len(digits) - 1:
                    ret.append(s + x)
                else:
                    q.append(s + x)
        return ret

solu = Solution()
print(solu.letterCombinations("234"))