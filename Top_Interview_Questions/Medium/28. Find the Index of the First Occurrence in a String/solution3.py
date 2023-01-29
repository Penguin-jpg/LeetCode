from typing import List


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        i, j = 0, 0
        table = self.build_table(needle)
        while i < len(haystack):
            if haystack[i] == needle[j]:
                i += 1
                j += 1
            if j == len(needle):
                return i - j
            if i < len(haystack) and haystack[i] != needle[j]:
                if j > 0:
                    j = table[j - 1]
                else:
                    i += 1
        return -1

    def build_table(self, pattern: str) -> List[int]:
        table = [0] * len(pattern)
        i, length = 1, 0
        while i < len(pattern):
            if pattern[i] == pattern[length]:
                length += 1
                table[i] = length
                i += 1
            else:
                if length != 0:
                    length = table[length - 1]
                else:
                    table[i] = 0
                    i += 1
        return table
