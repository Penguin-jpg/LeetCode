from typing import List
import math


class Solution:
    def countPrimes(self, n: int) -> int:
        if n == 0 or n == 1:
            return 0
        counter = 0
        is_prime = self.build_table(n)
        for i in range(0, n):
            if is_prime[i]:
                counter += 1
        return counter

    def build_table(self, n: int) -> List[bool]:
        table = [True for _ in range(n)]
        table[0], table[1] = False, False
        for i in range(2, int(math.sqrt(n)) + 1):
            if table[i]:
                for j in range(i * i, n, i):
                    table[j] = False
        return table
