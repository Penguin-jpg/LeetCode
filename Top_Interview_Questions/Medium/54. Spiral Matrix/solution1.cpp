#include <vector>
using namespace std;

/**
 * 想法: 用陣列紀錄該位置是否去過，分成四種狀況：
 *      1. 往右
 *          col+1 < lastRightCol && index < m*n -> col++
 *      2. 往下
 *          row+1 < lastDownRow && index < m*n -> row++
 *      3. 往左
 *          col-1 > lastLeftCol && index < m*n -> col--
 *      4. 往上
 *          row-1 > lastUpRow && index < m*n -> row--
 * 終止條件：results 的 index 已經到 m*n
 * 時間: O(n^2), 空間: O(1)
 */

class Solution
{
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int row = 0, col = 0, m = matrix.size(), n = matrix[0].size(), index = 1;
        // last row (up, down), last col(left, right) we stop at
        int lastUpRow = 0, lastDownRow = m, lastLeftCol = -1, lastRightCol = n;
        vector<int> results(m * n, matrix[0][0]);
        while (index < m * n)
        {
            while (col + 1 < lastRightCol && index < m * n) // right
            {
                col++;
                results[index] = matrix[row][col];
                index++;
            }
            lastRightCol = col;
            while (row + 1 < lastDownRow && index < m * n) // down
            {
                row++;
                results[index] = matrix[row][col];
                index++;
            }
            lastDownRow = row;
            while (col - 1 > lastLeftCol && index < m * n) // left
            {
                col--;
                results[index] = matrix[row][col];
                index++;
            }
            lastLeftCol = col;
            while (row - 1 > lastUpRow && index < m * n) // up
            {
                row--;
                results[index] = matrix[row][col];
                index++;
            }
            lastUpRow = row;
        }
        return results;
    }
};