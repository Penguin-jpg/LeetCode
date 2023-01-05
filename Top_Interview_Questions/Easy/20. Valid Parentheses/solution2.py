# 參考解答: 使用 hashmap 簡化判斷


class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        table = {"(": ")", "[": "]", "{": "}"}
        for char in s:
            if char == "(" or char == "[" or char == "{":
                stack.append(char)
            elif len(stack) == 0 or char != table[stack.pop()]:
                return False
        return len(stack) == 0
