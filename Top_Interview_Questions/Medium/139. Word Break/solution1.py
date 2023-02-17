from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        word_set = set(wordDict)
        dp = [False for _ in range(len(s) + 1)]
        dp[0] = True
        for i in range(1, len(s) + 1):
            for j in range(i - 1, -1, -1):
                if dp[j]:
                    if s[j:i] in word_set:
                        dp[i] = True
                        break
        return dp[-1]
