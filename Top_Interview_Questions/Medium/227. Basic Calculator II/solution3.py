class Solution:
    def calculate(self, s):
        nums, num, op = [], 0, "+"
        for i, ch in enumerate(s):
            if ch.isdigit():
                num = num * 10 + int(ch)
            # since python has no istringstream, we have to check every condition
            if (not ch.isdigit() and not ch.isspace()) or i == len(s) - 1:
                if op == "+":
                    nums.append(num)
                elif op == "-":
                    nums.append(-num)
                else:
                    num2 = nums.pop()
                    if op == "*":
                        nums.append(num2 * num)
                    else:
                        nums.append(int(num2 / num))
                op = ch
                num = 0
        return sum(nums)
