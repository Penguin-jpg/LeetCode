from collections import Counter


class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        max_length, table = 0, Counter(s)
        for num_unique_letters in range(1, len(table) + 1):
            left, right = 0, 0
            num_current_unique_letters = 0
            num_unique_letters_at_least_k = 0
            frequencies = [0] * 26
            while right < len(s):
                if num_current_unique_letters <= num_unique_letters:
                    letter = ord(s[right]) - ord("a")
                    frequencies[letter] += 1
                    num_current_unique_letters += 1 if frequencies[letter] == 1 else 0
                    num_unique_letters_at_least_k += 1 if frequencies[letter] == k else 0
                    right += 1
                else:
                    letter = ord(s[left]) - ord("a")
                    frequencies[letter] -= 1
                    num_current_unique_letters -= 1 if frequencies[letter] == 0 else 0
                    num_unique_letters_at_least_k -= 1 if frequencies[letter] == k - 1 else 0
                    left += 1
                if (
                    num_current_unique_letters == num_unique_letters
                    and num_unique_letters_at_least_k == num_unique_letters
                ):
                    max_length = max(max_length, right - left)
        return max_length
