class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = {}
        left, max_length = 0, 0
        for right in range(len(s)):
            if s[right] not in seen:
                max_length = max(max_length, right - left + 1)
            else:
                if seen[s[right]] < left:
                    max_length = max(max_length, right - left + 1)
                else:
                    left = seen[s[right]] + 1
            seen[s[right]] = right
        return max_length
