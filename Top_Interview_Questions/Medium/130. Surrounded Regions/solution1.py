from typing import List


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m, n = len(board), len(board[0])
        # you cannot use "flip = [[True for _ in range(n)]] * m" since it just create m reference to the same element)
        # e.g. change flip[0][1] will cause flip[i][1] for i=1,2,...,m to change
        flip = [[True for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if board[i][j] == "O" and (i == 0 or i == m - 1 or j == 0 or j == n - 1):
                    self.dfs(board, i, j, flip)
        for i in range(m):
            for j in range(n):
                if flip[i][j]:
                    board[i][j] = "X"

    def dfs(self, board: List[List[str]], row: int, col: int, flip: List[List[bool]]):
        if board[row][col] != "O" or not flip[row][col]:
            return
        print(row, col)
        flip[row][col] = False
        if row - 1 >= 0:
            self.dfs(board, row - 1, col, flip)
        if row + 1 < len(board):
            self.dfs(board, row + 1, col, flip)
        if col - 1 >= 0:
            self.dfs(board, row, col - 1, flip)
        if col + 1 < len(board[0]):
            self.dfs(board, row, col + 1, flip)
