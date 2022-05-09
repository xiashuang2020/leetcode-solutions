class Solution:
    def valid(self, s: str):
        leftp = 0
        rightp = 0
        for c in s:
            if c is "(":
                leftp += 1
            elif c is ")":
                rightp += 1
            if rightp > leftp:
                return False
        return True

    def removeInvalidParentheses(self, s: str):
        leftp = 0
        rightp = 0
        ret = set()

        if s is "":
            return [""]

        i = 0
        while i < len(s):
            if s[i] is "(":
                leftp += 1
            elif s[i] is ")":
                rightp += 1
            if rightp > leftp:
                for k in range(i + 1):
                    if s[k] is ")":
                        t = s[0:k] + s[k + 1:]
                        ret.add(t)
                ret2 = set()
                for t in ret:
                    ret2 = ret2.union(self.removeInvalidParentheses(t))
                return list(ret2)
            i += 1

        remove_left = leftp - rightp
        ret.add(s)

        while remove_left > 0:
            ret2 = set()
            for t in ret:
                for j in range(len(t)):
                    if t[j] is "(":
                        n = t[:j] + t[j + 1:]
                        if n not in ret2 and self.valid(n):
                            ret2.add(n)
            ret = ret2
            remove_left -= 1

        return list(ret)

x = Solution()
print(x.removeInvalidParentheses("()("))
print(x.removeInvalidParentheses("()())()"))
print(x.removeInvalidParentheses("(a)())()"))
print(x.removeInvalidParentheses(")("))
print(x.removeInvalidParentheses(")()))())))"))
