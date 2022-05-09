class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        i = len(s) - 1
        j = len(t) - 1
        backi = 0
        backj = 0

        while i >= 0 or j >= 0:
            while i >= 0 and s[i] is '#':
                i -= 1
                backi = 1
                while backi and i >= 0:
                    if s[i] is '#':
                        backi += 2
                    i -= 1
                    backi -= 1
            while j >= 0 and t[j] is '#':
                j -= 1
                backj = 1
                while backj and j >= 0:
                    if t[j] is '#':
                        backj += 2
                    j -= 1
                    backj -= 1

            if i >= 0 and j >= 0:
                if s[i] != t[j]:
                    return False
                i -= 1
                j -= 1
            elif i < 0 and j < 0:
                return True
            else:
                return False

        return True if i < 0 and j < 0 else False

solu = Solution()
print(solu.backspaceCompare("ab##", "c#d#"))
print(solu.backspaceCompare("cbc##", "cc#d#"))
print(solu.backspaceCompare("abc##", "cc#d#"))
print(solu.backspaceCompare("a##c", "#a#c"))
print(solu.backspaceCompare("bxj##tw", "bxj###tw"))
print(solu.backspaceCompare("nzp#o#g", "b#nzp#o#g"))

