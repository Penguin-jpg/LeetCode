from typing import List


class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                counter = 0
                for k in range(i - 1, i + 2):
                    if k >= 0 and k < m:
                        for l in range(j - 1, j + 2):
                            if l >= 0 and l < n and (board[k][l] == 1 or board[k][l] == 2):
                                counter += 1
                counter = counter - 1 if board[i][j] == 1 else counter
                if board[i][j] == 1:
                    if counter < 2 or counter > 3:
                        board[i][j] = 2
                elif counter == 3:
                    board[i][j] = 3
        for i in range(m):
            for j in range(n):
                if board[i][j] == 2:
                    board[i][j] = 0
                elif board[i][j] == 3:
                    board[i][j] = 1
