from typing import List


class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        results = [""] * n
        for i in range(1, n + 1):
            results[i - 1] = str(i)
        for i in range(2, n, 3):
            results[i] = "Fizz"
        for i in range(4, n, 5):
            results[i] = "Buzz"
        for i in range(14, n, 15):
            results[i] = "FizzBuzz"
        return results
