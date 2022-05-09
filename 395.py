class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        dict = {}
        ret = 0

        if s == "":
            return 0

        for c in s:
            if c not in dict:
                dict[c] = 0
            dict[c] += 1

        flag = 1
        for i in dict.values():
            if i < k:
                flag = 0
                break
        if flag:
            return len(s)

        i = 0
        j = 0
        while j < len(s):
            if dict[s[j]] < k:
                ret = max(ret, self.longestSubstring(s[i:j], k))
                i = j + 1
            j += 1

        ret = max(ret, self.longestSubstring(s[i:j], k))
        return ret

solu = Solution()
print(solu.longestSubstring("aaabb", 3))
print(solu.longestSubstring("ababbc", 2))
print(solu.longestSubstring("bbaaacbd", 3))