class Solution:
    def firstUniqChar(self, s: str) -> int:
        table, result = {}, -1
        for i, char in enumerate(s):
            if char not in table:
                table[char] = [i, 0]
            table[char][1] += 1
        for char, (pos, count) in table.items():
            if count == 1:
                result = min(result, pos) if result != -1 else pos
        return result
