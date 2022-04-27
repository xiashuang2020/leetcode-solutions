class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        l = s.split()
        if len(pattern) != len(l):
            return False

        h = {}
        h2 = {}
        for i, word in enumerate(l):
            c = pattern[i]
            if c not in h:
                if word in h2:
                    return False
                h[c] = word
                h2[word] = 1
            elif h[c] != word:
                return False

        return True


s = Solution()
print(s.wordPattern("aba", "I love I"))
print(s.wordPattern("aba", "I love You"))
print(s.wordPattern("abba", "foo foo foo foo"))
