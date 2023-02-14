#include <vector>
using namespace std;

/**
 * 想法: 透過 dfs 先把所有不能翻的找出來，剩下的都是可以翻的
 * 時間: O(m*n), 空間: O(m*n)
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
                    dfs(board, i, j, flip);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (flip[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>> &board, int row, int col, vector<vector<bool>> &flip)
    {
        if (board[row][col] != 'O' || !flip[row][col])
        {
            return;
        }
        flip[row][col] = false;
        // adjacent cells cannot be flipped either
        if (row - 1 >= 0)
        {
            dfs(board, row - 1, col, flip);
        }
        if (row + 1 < board.size())
        {
            dfs(board, row + 1, col, flip);
        }
        if (col - 1 >= 0)
        {
            dfs(board, row, col - 1, flip);
        }
        if (col + 1 < board[0].size())
        {
            dfs(board, row, col + 1, flip);
        }
    }
};