from typing import List


class Solution:
    def numDecodings(self, s: str) -> int:
        memo = [0] * 100
        return self.decode(s, 0, memo)

    def decode(self, s: str, index: int, memo: List[int]):
        if index >= len(s):
            return 1
        elif memo[index] != 0:
            return memo[index]
        result = 0
        if s[index] != "0":
            result += self.decode(s, index + 1, memo)
        if index + 1 < len(s) and (s[index] == "1" or (s[index] == "2" and s[index + 1] < "7")):
            result += self.decode(s, index + 2, memo)
        memo[index] = result
        return memo[index]
