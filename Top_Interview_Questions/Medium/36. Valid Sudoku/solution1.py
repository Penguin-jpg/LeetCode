from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            if not self.check_row(board, i):
                return False
            for j in range(9):
                if not self.check_col(board, j) or not self.check_grid(board, i, j):
                    return False
        return True

    def check_row(self, board: List[List[str]], row: int) -> bool:
        exists = [0] * 10
        for i in range(9):
            if board[row][i] != ".":
                exists[int(board[row][i])] += 1
        for i in range(1, 10):
            if exists[i] > 1:
                return False
        return True

    def check_col(self, board: List[List[str]], col: int) -> bool:
        exists = [0] * 10
        for i in range(9):
            if board[i][col] != ".":
                exists[int(board[i][col])] += 1
        for i in range(1, 10):
            if exists[i] > 1:
                return False
        return True

    def check_grid(self, board: List[List[str]], row: int, col: int) -> bool:
        grid_row, grid_col = (row // 3) * 3, (col // 3) * 3
        exists = [0] * 10
        for i in range(3):
            for j in range(3):
                if board[grid_row + i][grid_col + j] != ".":
                    exists[int(board[grid_row + i][grid_col + j])] += 1
        for i in range(1, 10):
            if exists[i] > 1:
                return False
        return True
