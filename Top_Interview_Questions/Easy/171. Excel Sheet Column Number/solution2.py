class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        return self.helper(columnTitle, 0)

    def helper(self, columnTitle: str, index: int) -> int:
        if index == len(columnTitle) - 1:
            return ord(columnTitle[index]) - ord("A") + 1
        return (ord(columnTitle[index]) - ord("A") + 1) * 26 ** (len(columnTitle) - index - 1) + self.helper(
            columnTitle, index + 1
        )
