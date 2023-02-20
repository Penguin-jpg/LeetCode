from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        result = []
        return self.calculate(tokens, 0, result)

    def is_number(self, str: str) -> bool:
        return (str[0] == "-" and str[1] >= "0" and str[1] <= 9) or (str[0] >= "0" and str[0] <= "9")

    def is_operator(self, str: str) -> bool:
        return str == "+" or str == "-" or str == "*" or str == "/"

    def calculate(self, tokens: List[str], index: int, result: List[int]) -> int:
        if index >= len(tokens):
            return result[-1]
        if self.is_operator(tokens[index]):
            first = result.pop()
            second = result.pop()
            if tokens[index] == "+":
                result.append(second + first)
            elif tokens[index] == "-":
                result.append(second - first)
            elif tokens[index] == "*":
                result.append(second * first)
            elif tokens[index] == "/":
                result.append(int(second / first))
        else:
            result.append(int(tokens[index]))
        return self.calculate(tokens, index + 1, result)
