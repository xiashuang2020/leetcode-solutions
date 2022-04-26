class Solution:
    def diffWaysToCompute(self, expression: str, m={}):
        if expression in m:
            return m[expression]
        elif expression.isdigit():
            m[expression] = [int(expression)]
            return m[expression]

        i = 0
        ret = []

        def helper(a, b, o):
            if o is "+":
                return a + b
            elif o is "-":
                return a - b
            else:
                return a * b

        while i < len(expression):
            if expression[i] in "+-*":
                lista = self.diffWaysToCompute(expression[:i], m)
                listb = self.diffWaysToCompute(expression[i + 1:], m)
                for x in lista:
                    for y in listb:
                        ret.append(helper(x, y, expression[i]))
            i = i + 1

        m[expression] = ret
        return ret

solution = Solution()
print(solution.diffWaysToCompute("2-1-1"))
print(solution.diffWaysToCompute("2*3-4*5"))


