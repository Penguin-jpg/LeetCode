#include <vector>
using namespace std;

/**
 * 參考解答: 由於螺旋的特性，所以一開始往右 m 步，往下 n 步，往左 m-1 步，
 * 往上 n-1 步，下一輪就往右 m-2 步...，按照這個規律寫出
 * 時間: O(n^2), 空間: O(1)
 */

class Solution
{
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<vector<int>> directions({{0, 1}, {1, 0}, {0, -1}, {-1, 0}}); // right, up, left, down
        int m = matrix.size(), n = matrix[0].size();
        vector<int> results(m * n);
        // {steps_to_move_along_col, steps_to_move_along_row}, m-1 since we start from row 0
        vector<int> steps({n, m - 1});
        int directionIndex = 0, row = 0, col = -1, index = 0;
        while (steps[directionIndex % 2] > 0) // mod 2 to decide move row or col (0 for col; 1 for row)
        {
            for (int i = 0; i < steps[directionIndex % 2]; i++)
            {
                row += directions[directionIndex][0];
                col += directions[directionIndex][1];
                results[index] = matrix[row][col];
                index++;
            }
            steps[directionIndex % 2]--;               // decrease number of steps need to go next time
            directionIndex = (directionIndex + 1) % 4; // to next direction
        }
        return results;
    }
};