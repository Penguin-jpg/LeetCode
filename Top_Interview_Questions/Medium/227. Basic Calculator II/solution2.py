class Solution:
    def calculate(self, s):
        operators, nums, num = [], [], 0
        for ch in s + "#":
            if ch == " ":
                continue
            elif ch.isdigit():
                num = num * 10 + int(ch)
            else:
                nums.append(num)
                while operators and self.get_precedence(ch) <= self.get_precedence(operators[-1]):
                    num1, num2, op = nums.pop(), nums.pop(), operators.pop()
                    if op == "*":
                        nums.append(num2 * num1)
                    elif op == "/":
                        nums.append(num2 // num1)
                    elif op == "+":
                        nums.append(num2 + num1)
                    elif op == "-":
                        nums.append(num2 - num1)
                operators.append(ch)
                num = 0

        return nums.pop()

    def get_precedence(self, ch: str) -> int:
        if ch == "*" or ch == "/":
            return 3
        elif ch == "+" or ch == "-":
            return 2
        else:
            return 1
