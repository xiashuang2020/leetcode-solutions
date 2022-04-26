class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        l = s.split()
        if len(pattern) != len(l):
            return False

        h = {}
        for i, word in enumerate(l):
            c = pattern[i]
            if c not in h:
                h[c] = word
            elif h[c] != word:
                return False

        return True


s = Solution()
print(s.wordPattern("aba", "I love I"))
print(s.wordPattern("aba", "I love You"))
