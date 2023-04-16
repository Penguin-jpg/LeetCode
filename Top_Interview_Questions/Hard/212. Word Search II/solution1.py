from typing import List


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        m, n = len(board), len(board[0])
        results = []
        for i in range(m):
            for j in range(n):
                for k in range(len(words)):
                    if words[k] != "" and m * n >= len(words[k]) and self.dfs(board, i, j, words[k], 0, m, n):
                        results.append(words[k])
                        words[k] = ""
        return results

    def dfs(self, board: List[List[str]], row: int, col: int, word: str, index: int, m: int, n: int) -> bool:
        if index >= len(word):
            return True
        elif row < 0 or row >= m or col < 0 or col >= n or board[row][col] != word[index]:
            return False
        temp = board[row][col]
        board[row][col] = "*"
        found = (
            self.dfs(board, row - 1, col, word, index + 1, m, n)
            or self.dfs(board, row + 1, col, word, index + 1, m, n)
            or self.dfs(board, row, col - 1, word, index + 1, m, n)
            or self.dfs(board, row, col + 1, word, index + 1, m, n)
        )
        board[row][col] = temp
        return found
