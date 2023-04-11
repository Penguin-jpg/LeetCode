from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        words = set(wordDict)
        memo = {}
        return self.dfs(s, words, memo)

    def dfs(self, s: str, words: set, memo: dict) -> List[str]:
        if s in memo:
            return memo[s]
        results = []
        if s in words:
            results.append(s)
        for i in range(1, len(s)):
            sub = s[i:]
            if sub in words:
                remain = s[:i]
                sub_list = self.dfs(remain, words, memo)
                for result in sub_list:
                    results.append(result + " " + sub)
        memo[s] = results
        return results
