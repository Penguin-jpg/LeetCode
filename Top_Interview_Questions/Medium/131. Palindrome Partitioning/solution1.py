from typing import List


class Solution:
    def partition(self, s: str) -> List[List[str]]:
        results, temp = [], []
        self.backtracking(s, 0, temp, results)
        return results

    def is_palindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        while i <= j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True

    def backtracking(self, s: str, index: int, temp: List[str], results: List[List[str]]):
        if index >= len(s):
            results.append(temp[:])
            return
        for i in range(1, len(s) + 1):
            if index + i > len(s):
                break
            sub = s[index : index + i]
            if self.is_palindrome(sub):
                temp.append(sub)
                self.backtracking(s, index + i, temp, results)
                temp.pop()
