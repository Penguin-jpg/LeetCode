class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        table = {}
        for char in s:
            if char not in table:
                table[char] = 0
            table[char] += 1
        for char in t:
            if char not in table or table[char] < 1:
                return False
            table[char] -= 1
        return True
