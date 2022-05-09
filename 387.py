class Solution:
    def firstUniqChar(self, s: str) -> int:
        cnts = [0 for x in range(26)]
        idxs = [-1 for x in range(26)]

        for i, c in enumerate(s):
            p = ord(c) - ord('a')
            cnts[p] += 1
            if idxs[p] == -1:
                idxs[p] = i

        ret = -1
        for i, idx in enumerate(idxs):
            if cnts[i] == 1 and (ret == -1 or idx < ret):
                ret = idx

        return ret

solu = Solution()
print(solu.firstUniqChar("loveleetcode"))