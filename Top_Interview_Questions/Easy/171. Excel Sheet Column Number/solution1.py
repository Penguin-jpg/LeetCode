class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        length, result = len(columnTitle), 0
        for char in columnTitle:
            result += (ord(char) - ord("A") + 1) * 26 ** (length - 1)
            length -= 1
        return result
