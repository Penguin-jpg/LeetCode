from typing import List


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                if board[i][j] == "O" and (i == 0 or i == m - 1 or j == 0 or j == n - 1):
                    self.dfs(board, i, j, m, n)
        for i in range(m):
            for j in range(n):
                if board[i][j] == "N":
                    board[i][j] = "O"
                elif board[i][j] == "O":
                    board[i][j] = "X"

    def dfs(self, board: List[List[str]], row: int, col: int, m: int, n: int):
        if board[row][col] != "O" or board[row][col] == "N":
            return
        board[row][col] = "N"
        if row - 1 >= 0:
            self.dfs(board, row - 1, col, m, n)
        if row + 1 < len(board):
            self.dfs(board, row + 1, col, m, n)
        if col - 1 >= 0:
            self.dfs(board, row, col - 1, m, n)
        if col + 1 < len(board[0]):
            self.dfs(board, row, col + 1, m, n)
