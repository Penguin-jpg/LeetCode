from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.word_search(board, word, 0, i, j):
                    return True
        return False

    def word_search(self, board: List[List[str]], word: str, index: int, row: int, col: int):
        if index >= len(word):
            return True
        if row < 0 or col < 0 or row >= len(board) or col >= len(board[0]) or board[row][col] != word[index]:
            return False
        temp = board[row][col]
        board[row][col] = "*"
        found = (
            self.word_search(board, word, index + 1, row - 1, col)
            or self.word_search(board, word, index + 1, row, col - 1)
            or self.word_search(board, word, index + 1, row + 1, col)
            or self.word_search(board, word, index + 1, row, col + 1)
        )
        board[row][col] = temp
        return found
