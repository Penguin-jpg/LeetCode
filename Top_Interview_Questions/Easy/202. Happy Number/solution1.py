class Solution:
    def isHappy(self, n: int) -> bool:
        table = {}
        while n != 1:
            if n in table:
                return False
            table[n] = True
            n = sum([int(digit) ** 2 for digit in str(n)])
        return True
