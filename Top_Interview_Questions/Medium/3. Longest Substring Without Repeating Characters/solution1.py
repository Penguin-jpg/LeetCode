class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chars = set()
        start, i, current_length, max_length = 0, 0, 0, 0
        while i != len(s):
            if s[i] in chars:
                start += 1
                i = start
                max_length = max(current_length, max_length)
                current_length = 0
                chars.clear()
                continue
            chars.add(s[i])
            current_length += 1
            i += 1
        return max(current_length, max_length)
