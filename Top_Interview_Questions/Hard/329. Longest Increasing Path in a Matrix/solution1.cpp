#include <vector>
using namespace std;

/**
 * 想法: dfs找出所有 increasing path，再取最長的 (TLE)
 * 時間:
 *   - 直觀: O(m*n*4^(m*n)) (m*n: 整個陣列跑一次；4^(m*n): 陣列上每個都有 4 種方向可選)
 *   - 較準確: O(m*n*3^(m*n)) (m*n: 整個陣列跑一次；3^(m*n): 實際上最多只會額外往 3 個方向，因為不會回頭)
 * 空間: O(m*n)
 */

class Solution
{
  public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int result = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                result = max(result, dfs(matrix, i, j, -1));
            }
        }
        return result;
    }

    int dfs(vector<vector<int>> &matrix, int row, int col, int last)
    {
        if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size() || matrix[row][col] == -1 ||
            matrix[row][col] <= last)
        {
            return 0;
        }
        int temp = matrix[row][col];
        matrix[row][col] = -1; // mark as visited
        int up = 1 + dfs(matrix, row - 1, col, temp);
        int down = 1 + dfs(matrix, row + 1, col, temp);
        int left = 1 + dfs(matrix, row, col - 1, temp);
        int right = 1 + dfs(matrix, row, col + 1, temp);
        matrix[row][col] = temp; // mark as unvisited
        return max(up, max(down, max(left, right)));
    }
};