from typing import List


class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        m, n = len(board), len(board[0])
        states = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                counter = 0
                for k in range(i - 1, i + 2):
                    if k >= 0 and k < m:
                        for l in range(j - 1, j + 2):
                            if l >= 0 and l < n and board[k][l] == 1:
                                counter += 1
                counter = counter - 1 if board[i][j] == 1 else counter
                if board[i][j] == 1:
                    if counter < 2 or counter > 3:
                        states[i][j] = 0
                    else:
                        states[i][j] = 1
                elif counter == 3:
                    states[i][j] = 1
                else:
                    states[i][j] = 0
        for i in range(m):
            for j in range(n):
                board[i][j] = states[i][j]
