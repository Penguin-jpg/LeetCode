#include <vector>
using namespace std;

/**
 * 參考解答: 為了要做到題目要求的 in-place，不能夠用額外的陣列紀錄矩陣狀態，
 * 所以改成用第一個 row 和 column 來記錄，當 matrix[i][0]=0 時，就代表該 row i
 * 必須是 zero row；當 matrix[0][j]=0 時，就代表該 column j 必須是 zero
 * column，但因為要使用第一個 row 和 column 紀錄，所以必須幫這兩者獨立處理
 * 時間: O(mn), m: row元素數量; n: column元素數量, 空間: O(1)
 */

class Solution
{
  public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // if first row (column) is zero row (column)
        bool isZeroRow = false, isZeroCol = false;
        for (int i = 0; i < matrix[0].size(); i++) // handle first row
        {
            if (matrix[0][i] == 0)
            {
                isZeroRow = true;
                break;
            }
        }
        for (int j = 0; j < matrix.size(); j++) // handle first column
        {
            if (matrix[j][0] == 0)
            {
                isZeroCol = true;
                break;
            }
        }
        // handle the rest rows and columns
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0) // store state to first row and column
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // turn rows and columns to zero rows and columns (except first row and column)
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        // turn first row and column to zeros
        if (isZeroRow)
        {
            for (int i = 0; i < matrix[0].size(); i++)
            {
                matrix[0][i] = 0;
            }
        }
        if (isZeroCol)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};