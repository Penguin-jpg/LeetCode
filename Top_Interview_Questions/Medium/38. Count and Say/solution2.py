import itertools

# 參考解答: 用 itertools 的 groupby 把相同的區塊 group 起來 (python才能用)


class Solution:
    def countAndSay(self, n: int) -> str:
        result = "1"
        for _ in range(2, n + 1):
            temp = ""
            for digit, group in itertools.groupby(result):
                count = len(list(group))  # group size is the count of that digit
                temp += f"{count}{digit}"
            result = temp
        return result
