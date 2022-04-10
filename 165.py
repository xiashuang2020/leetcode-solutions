from itertools import zip_longest


class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        l1 = version1.split(".")
        l2 = version2.split(".")

        for a,b in zip_longest(l1, l2, fillvalue="0"):
            a = int(a)
            b = int(b)
            if a > b:
                return 1
            elif a < b:
                return -1

        return 0

solution = Solution()
print(solution.compareVersion("1.01", "1.001"))
print(solution.compareVersion("1.0", "1.0.0"))
print(solution.compareVersion("0.1", "1.1"))

