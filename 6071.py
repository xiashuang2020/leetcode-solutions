class Solution:
    def minimumRounds(self, tasks) -> int:
        m = {}
        ret = 0
        for t in tasks:
            if t in m:
                m[t] = m[t] + 1
            else:
                m[t] = 1

        for k, v in m.items():
            if v == 1:
                return -1
            elif v % 3 == 0:
                ret += v // 3
            elif v % 3 == 2:
                ret += 1 + (v - 2) // 3
            else:
                ret += 2 + (v - 4) // 3
        return ret


s = Solution()
print(s.minimumRounds([2, 2, 3, 3, 2, 4, 4, 4, 4, 4]))
print(s.minimumRounds([2, 2, 3, 3, 2, 4, 4, 4, 4, 4, 5]))