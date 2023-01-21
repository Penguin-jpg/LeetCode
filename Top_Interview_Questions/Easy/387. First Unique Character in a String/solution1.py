class Solution:
    def firstUniqChar(self, s: str) -> int:
        table, pos = {}, {}
        result = -1
        for i, char in enumerate(s):
            if char not in pos:
                pos[char] = i
            if char not in table:
                table[char] = 0
            table[char] += 1
        for char, count in table.items():
            if count == 1:
                result = min(result, pos[char]) if result != -1 else pos[char]
        return result
