# solution3的python版


class Solution:
    def romanToInt(self, s: str) -> int:
        table = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        result, length = 0, len(s)
        for index in range(length):
            if index + 1 < length and table[s[index]] < table[s[index + 1]]:
                result -= table[s[index]]
            else:
                result += table[s[index]]
        return result
