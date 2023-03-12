#include <vector>
using namespace std;

/**
 * 想法: 我們可以利用每個 row 和 column 均是由小排到大的特性，從第
 * 一個 row 的最右邊開始檢查，做出以下判斷：
 *      1. matrix[row][col]==target -> return true
 *      2. matrix[row][col]<target -> 這一 row 絕對都比 target 更小，直接跳到下一個
 *         row -> row++
 *      3. matrix[row][col]>target -> 這一 column 絕對都比 target 更大，直接跳到前一
 *         個 column -> col++
 * 時間: O(m+n) 空間: O(1)
 */

class Solution
{
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = 0, col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] < target)
            {
                row++;
            }
            else
            {
                col--;
            }
        }
        return false;
    }
};