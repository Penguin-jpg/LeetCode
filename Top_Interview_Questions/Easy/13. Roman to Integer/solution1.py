# 因為 python 全部都用字串表示，所以寫一起就好


class Solution:
    def romanToInt(self, s: str) -> int:
        table = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
            "IV": 4,
            "IX": 9,
            "XL": 40,
            "XC": 90,
            "CD": 400,
            "CM": 900,
        }
        result, index, length = 0, 0, len(s)
        while index < length:
            if index + 1 < length:
                sub = s[index : index + 2]
                if sub in table:
                    result += table[sub]
                    index += 2
                else:
                    result += table[s[index]]
                    index += 1
            else:
                result += table[s[index]]
                index += 1
        return result
