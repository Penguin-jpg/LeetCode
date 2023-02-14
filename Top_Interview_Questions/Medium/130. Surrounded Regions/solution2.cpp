#include <vector>
using namespace std;

/**
 * 想法: solution1改良版，直接用 N 代表不可翻轉並改在 board 上，可以省掉儲存
 * flip 的空間
 * 時間: O(m*n), 空間: O(1)
 */

class Solution
{
  public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> flip(m, vector<bool>(n, true));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // start from cell at the edge of board
                if (board[i][j] == 'O' && (i == 0 || i == m - 1 || j == 0 || j == n - 1))
                {
                    dfs(board, i, j, m, n);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'N') // cannot flip
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') // can flip
                {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>> &board, int row, int col, int m, int n)
    {
        if (board[row][col] != 'O' || board[row][col] == 'N')
        {
            return;
        }
        board[row][col] = 'N';
        // adjacent cells cannot be flipped either
        if (row - 1 >= 0)
        {
            dfs(board, row - 1, col, m, n);
        }
        if (row + 1 < m)
        {
            dfs(board, row + 1, col, m, n);
        }
        if (col - 1 >= 0)
        {
            dfs(board, row, col - 1, m, n);
        }
        if (col + 1 < n)
        {
            dfs(board, row, col + 1, m, n);
        }
    }
};