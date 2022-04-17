class Solution:
    def calculate(self, s: str) -> int:
        s = s.replace("+", " + ")
        s = s.replace("-", " - ")
        s = s.replace("*", " * ")
        s = s.replace("/", " / ")
        s = s.split()

        nums = []
        ops = []
        for o in s:
            if o is "+" or o is "-" or o is "*" or o is "/":
                ops.append(o)
            else:
                n = int(o)
                if ops and (ops[-1] is "*" or ops[-1] is "/"):
                    op = ops.pop()
                    p = nums.pop()
                    if op is "*":
                        n = p * n
                    else:
                        n = p // n
                nums.append(n)

        i = 0
        p = nums[0]
        while i < len(ops):
            q = nums[i + 1]
            if ops[i] is "+":
                p = p + q
            else:
                p = p - q
            i = i + 1
        return p

s = Solution()
print(s.calculate("2 + 5/2"))
print(s.calculate("3+2*2"))