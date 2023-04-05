from collections import Counter


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        left, remain_length, result = 0, len(t), ""
        table = Counter(t)
        for right in range(len(s)):
            if s[right] in table:
                remain_length -= 1 if table[s[right]] > 0 else 0
                table[s[right]] -= 1
            while remain_length == 0:
                length = right - left + 1
                if result == "" or length < len(result):
                    result = s[left : right + 1]
                if s[left] in table:
                    table[s[left]] += 1
                    remain_length += 1 if table[s[left]] > 0 else 0
                left += 1
        return result
