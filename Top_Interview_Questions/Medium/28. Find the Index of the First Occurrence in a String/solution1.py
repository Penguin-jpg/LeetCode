class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        left, right = 0, len(needle) - 1
        while right < len(haystack):
            for i in range(len(needle)):
                if haystack[left + i] != needle[i]:
                    left += 1
                    right += 1
                    break
            if haystack[left : right + 1] == needle:
                return left
        return -1
