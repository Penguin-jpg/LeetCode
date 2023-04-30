#include <vector>
using namespace std;

/**
 * 想法: 因為重複走過的路徑太多超時了，所以用 dp memo法紀錄走過的最大路徑長度
 * 時間: O(m*n), 空間: O(m*n)
 */

class Solution
{
  public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int result = 0;
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), -1));
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                result = max(result, dfs(matrix, i, j, -1, memo));
            }
        }
        return result;
    }

    int dfs(vector<vector<int>> &matrix, int row, int col, int last, vector<vector<int>> &memo)
    {
        if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size() || matrix[row][col] == -1 ||
            matrix[row][col] <= last)
        {
            return 0;
        }
        if (memo[row][col] != -1)
        {
            return memo[row][col];
        }
        int temp = matrix[row][col];
        matrix[row][col] = -1; // mark as visited
        int up = 1 + dfs(matrix, row - 1, col, temp, memo);
        int down = 1 + dfs(matrix, row + 1, col, temp, memo);
        int left = 1 + dfs(matrix, row, col - 1, temp, memo);
        int right = 1 + dfs(matrix, row, col + 1, temp, memo);
        matrix[row][col] = temp; // mark as unvisited
        memo[row][col] = max(up, max(down, max(left, right)));
        return memo[row][col];
    }
};