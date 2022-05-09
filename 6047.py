class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        def cmp(a, b):
            if a is "":
                return True
            for i in range(len(a)):
                if b[i] > a[i]:
                    return True
                elif b[i] < a[i]:
                    return False
            return False
        m = ""
        for i in range(len(number)):
            if number[i] == digit:
                n = number[0:i] + number[i + 1:]
                if cmp(m, n):
                    m = n
        return m

solu = Solution()
#print(solu.removeDigit("123", "3"))
print(solu.removeDigit("1231", "1"))
print(solu.removeDigit("551", "5"))