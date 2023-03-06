class Solution:
    def calculate(self, s: str) -> int:
        s = self.to_postfix(s)
        nums = []
        i = 0
        while i < len(s):
            if s[i].isdigit():
                j = s.find("|", i + 1)
                nums.append(int(s[i:j]))
                i = j
            else:
                num1, num2 = nums.pop(), nums.pop()
                if s[i] == "+":
                    nums.append(num2 + num1)
                elif s[i] == "-":
                    nums.append(num2 - num1)
                elif s[i] == "*":
                    nums.append(num2 * num1)
                else:
                    nums.append(num2 // num1)
            i += 1
        return nums[-1]

    def get_precedence(self, ch: str) -> int:
        if ch == "*" or ch == "/":
            return 3
        elif ch == "+" or ch == "-":
            return 2
        else:
            return 1

    def to_postfix(self, s: str) -> str:
        operators = []
        postfix = ""
        for ch in s:
            if ch == " ":
                continue
            elif ch.isdigit():
                postfix += ch
            else:
                postfix += "|"
                while len(operators) != 0 and self.get_precedence(ch) <= self.get_precedence(operators[-1]):
                    postfix += operators.pop()
                operators.append(ch)
        postfix += "|"
        while len(operators) != 0:
            postfix += operators.pop()
        return postfix
