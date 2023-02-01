#include <vector>
using namespace std;

/**
 * 想法: 觀察規律，以 4x4 矩陣為例：
 *      00 -> 03
 *      01 -> 13
 *      02 -> 23
 *      03 -> 33
 *      10 -> 02
 *      11 -> 12 ...
 * 可推出 ij -> j(n-i-1) (概念對但不符合題目要求的 in-place)
 * 時間: O(n^2), 空間: O(n^2)
 */

class Solution
{
  public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> original = matrix;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[j][n - i - 1] = original[i][j];
            }
        }
    }
};