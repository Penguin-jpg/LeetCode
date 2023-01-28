from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        results = []
        self.generate(results, "", n, n)
        return results

    def generate(self, results: List[str], parenthesis, left, right):
        if left == 0 and right == 0:
            results.append(parenthesis)
            return
        if left > 0:
            self.generate(results, parenthesis + "(", left - 1, right)
        if right > left:
            self.generate(results, parenthesis + ")", left, right - 1)
