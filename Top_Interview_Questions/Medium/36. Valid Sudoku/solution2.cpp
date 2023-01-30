#include <vector>
using namespace std;

/**
 * 參考解答: 用陣列的方式將 row, col, grid 出現的數字都存起來，當檢查時如果重複出現就可以直接中斷
 * 時間: O(n^2), 空間: O(n^2)
 */

class Solution
{
  public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int rowNums[10][10] = {0};    // rowNums[i][j] means number j in row i
        int colNums[10][10] = {0};    // colNums[i][j] means number j in col i
        int gridNums[3][3][10] = {0}; // 3*3 sub-grids
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    int gridRow = i / 3, gridCol = j / 3;
                    rowNums[i][num]++, colNums[j][num]++, gridNums[gridRow][gridCol][num]++;
                    if (rowNums[i][num] > 1 || colNums[j][num] > 1 || gridNums[gridRow][gridCol][num] > 1)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};