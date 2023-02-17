from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        word_set = set(wordDict)
        memo = {}
        return self.find_word(s, 0, word_set, memo)

    def find_word(self, s: str, start: int, word_set: set, memo: dict) -> bool:
        if start >= len(s):
            return True
        elif start in memo:
            return memo[start]
        for i in range(start + 1, len(s) + 1):
            if s[start:i] in word_set:
                if self.find_word(s, i, word_set, memo):
                    memo[start] = True
                    return memo[start]
        memo[start] = False
        return memo[start]
