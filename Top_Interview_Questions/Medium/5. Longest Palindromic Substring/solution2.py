class Solution:
    def longestPalindrome(self, s: str) -> str:
        start, max_length, size = 0, 0, len(s)
        for i in range(size):
            left, right = i, i
            while left >= 0 and right < size and s[left] == s[right]:
                left -= 1
                right += 1
            if max_length < right - left - 1:
                max_length = right - left - 1
                start = left + 1
        for i in range(size):
            left, right = i, i + 1
            while left >= 0 and right < size and s[left] == s[right]:
                left -= 1
                right += 1
            if max_length < right - left - 1:
                max_length = right - left - 1
                start = left + 1
        return s[start : start + max_length]
