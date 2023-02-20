from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        result = []
        for token in tokens:
            if self.is_operator(token):
                first = result.pop()
                second = result.pop()
                if token == "+":
                    result.append(second + first)
                elif token == "-":
                    result.append(second - first)
                elif token == "*":
                    result.append(second * first)
                elif token == "/":
                    result.append(int(second / first))
            else:
                result.append(int(token))
        return result[-1]

    def is_number(self, str: str) -> bool:
        return (str[0] == "-" and str[1] >= "0" and str[1] <= 9) or (str[0] >= "0" and str[0] <= "9")

    def is_operator(self, str: str) -> bool:
        return str == "+" or str == "-" or str == "*" or str == "/"
