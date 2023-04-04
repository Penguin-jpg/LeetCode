class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        return self.match(s, p, 0, 0)

    def match(self, s: str, p: str, i: int, j: int) -> bool:
        if j == len(p):
            return i == len(s)
        elif p[j] == "*":
            if self.match(s, p, i, j + 1):
                return True
            else:
                while i < len(s):
                    i += 1
                    if self.match(s, p, i, j):
                        return True
        elif i < len(s) and (p[j] == s[i] or p[j] == "?"):
            return self.match(s, p, i + 1, j + 1)
        return False
