import string


class Solution:
    def numDecodings(self, s: str) -> int:
        counter, length = 0, len(s)
        table = {str(index + 1): letter for index, letter in enumerate(string.ascii_lowercase)}
        self.decode(s, 0, counter, table)
        return counter

    def decode(self, s: str, index: int, counter: int, table: dict):
        if index >= len(s):
            counter += 1
            return
        for i in range(1, 3):
            if index + i > len(s):
                return
            sub = s[index : index + i]
            if sub not in table:
                return
            self.decode(s, index + i, counter, table)
