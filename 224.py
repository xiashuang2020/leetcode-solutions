class Solution:
    def calculate(self, s: str) -> int:
        s = s.replace("+", " + ")
        s = s.replace("-", " - ")
        s = s.replace("(", " ( ")
        s = s.replace(")", " ) ")
        s = s.split()

        stack = []

        for o in s:
            if o == "+" or o == '-' or o == "(":
                stack.append(o)
            else:
                if o is ")":
                    n = stack.pop()
                    if stack[-1] is not "(":
                        print("error should not happen")
                    stack.pop()
                else:
                    n = int(o)
                while stack and (stack[-1] is '+' or stack[-1] is "-"):
                    op = stack.pop()
                    if op is '+':
                        p = stack.pop()
                        n = n + p
                    else:
                        if len(stack) == 0 or stack[-1] is "(":
                            n = -1 * n
                        else:
                            p = stack.pop()
                            n = p - n

                stack.append(n)

        return stack[0]


solution = Solution()
print(solution.calculate("-1"))
print(solution.calculate("1+1"))
print(solution.calculate("1+(2 - 3)"))
print(solution.calculate("2 + 1 - 2"))
print(solution.calculate("(1+(4+5+2)-3)+(6+8)"))
print(solution.calculate("1-(-2)"))


