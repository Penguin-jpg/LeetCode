from typing import List


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        memo = [[-1 for _ in range(len(p) + 1)] for _ in range(len(s) + 1)]
        return self.match(s, p, 0, 0, memo)

    def match(self, s: str, p: str, i: int, j: int, memo: List[List[int]]) -> bool:
        if memo[i][j] != -1:
            return memo[i][j]
        if j == len(p):
            memo[i][j] = i == len(s)
            return memo[i][j]
        if j + 1 < len(p) and p[j + 1] == "*":
            if self.match(s, p, i, j + 2, memo) or (
                i < len(s) and (p[j] == s[i] or p[j] == ".") and self.match(s, p, i + 1, j, memo)
            ):
                memo[i][j] = 1
                return memo[i][j]
        elif i < len(s) and (p[j] == s[i] or p[j] == "."):
            memo[i][j] = self.match(s, p, i + 1, j + 1, memo)
            return memo[i][j]
        memo[i][j] = False
        return memo[i][j]
