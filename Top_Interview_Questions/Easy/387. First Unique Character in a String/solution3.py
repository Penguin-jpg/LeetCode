class Solution:
    def firstUniqChar(self, s: str) -> int:
        table = {}
        for char in s:
            if char not in table:
                table[char] = 0
            table[char] += 1
        for i, char in enumerate(s):
            if table[char] == 1:
                return i
        return -1
