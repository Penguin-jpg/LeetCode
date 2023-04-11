from typing import List

# 跑不動，不知道為什麼


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        words = set(wordDict)
        results, slices = [], []
        self.backtracking(s, 0, len(s), slices, words, results)
        return results

    def backtracking(
        self, s: str, start: int, numSlices: int, slices: List[str], words: set, results: List[str]
    ):
        if start >= len(s):
            results.append("".join(slices))
            return
        for i in range(1, numSlices + 1):
            sub = s[start : start + i + 1]
            if sub in words:
                slices.append(sub)
                self.backtracking(s, start + i, numSlices - i, slices, words, results)
                slices.pop()
