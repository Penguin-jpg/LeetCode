class Solution:
    def trailingZeroes(self, n: int) -> int:
        counter = 0
        exp = []
        temp, val = 5, 1
        while temp <= n:
            exp.append((temp, val))
            temp *= 5
            val += 1
        for i in range(5, n + 1, 5):
            for j in range(len(exp) - 1, -1, -1):
                if i % exp[j][0] == 0:
                    counter += exp[j][1]
                    break
        return counter
