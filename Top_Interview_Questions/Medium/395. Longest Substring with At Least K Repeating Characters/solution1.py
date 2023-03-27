from typing import List


class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        max_length, n = 0, len(s)
        for left in range(0, n):
            table = [0] * 26
            for right in range(left, n):
                table[ord(s[right]) - ord("a")] += 1
                if self.is_valid(table, k):
                    max_length = max(max_length, right - left + 1)
        return max_length

    def is_valid(self, table: List[int], k: int) -> bool:
        num_unique_letters = 0
        num_unique_letters_at_least_k = 0
        for i in range(0, 26):
            num_unique_letters += 1 if table[i] > 0 else 0
            num_unique_letters_at_least_k += 1 if table[i] >= k else 0
        return num_unique_letters == num_unique_letters_at_least_k
