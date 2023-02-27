#include <vector>
using namespace std;

/**
 * 想法: 透過觀察可以發現，只要存在"1"的地方一定會形成一座島，我們只需要確定島的
 * 面積占多大即可，而要完整探完整個面積最方便的方式就是 DFS，用個迴圈去找，找到
 * "1"時就做 DFS把所有相連的"1"找完並改成"x"，再把 counter+1，最後回傳 counter
 * 時間: O(m*n), 空間: O(1)
 */

class Solution
{
  public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), counter = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j, m, n);
                    counter++;
                }
            }
        }
        return counter;
    }

    void dfs(vector<vector<char>> &grid, int row, int col, int m, int n)
    {
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != '1')
        {
            return;
        }
        grid[row][col] = 'x';
        dfs(grid, row + 1, col, m, n);
        dfs(grid, row - 1, col, m, n);
        dfs(grid, row, col + 1, m, n);
        dfs(grid, row, col - 1, m, n);
    }
};