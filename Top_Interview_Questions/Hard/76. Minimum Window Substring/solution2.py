from collections import Counter


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        left, remain_length, start, min_length = 0, len(t), 0, -1
        table = Counter(t)
        for right in range(len(s)):
            if table[s[right]] > 0:
                remain_length -= 1
            table[s[right]] -= 1
            while remain_length == 0:
                length = right - left + 1
                if min_length == -1 or length < min_length:
                    start = left
                    min_length = length
                table[s[left]] += 1
                if table[s[left]] > 0:
                    remain_length += 1
                left += 1
        return "" if min_length == -1 else s[start : start + min_length]
